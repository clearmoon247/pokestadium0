#!/usr/bin/env python3
"""Compare donor library ROM functions with Zero assembly-owner extents.

This is ROM evidence, not proof that donor C compiles identically for Zero.
Symbols and YAML delimit inferred extents; no ROM bytes are emitted.
"""
import argparse
from collections import Counter, defaultdict
import csv
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess

import yaml

from map_fragment_sections import load_image
from map_rom import EXPECTED_SHA256

ROOT = Path(__file__).resolve().parents[1]
SYMBOL = re.compile(r"^\s*(\w+)\s*=\s*(0x[0-9a-fA-F]+)\s*;")
TARGETS = {
    "stadium1": ("pokestadium", "ed1378bc12115f71209a77844965ba50"),
    "stadium2": ("pokestadiumgs", "1561c75d11cedf356a8ddb1a4a5f9d5d"),
}


def words(data):
    return list(struct.unpack(f">{len(data) // 4}I", data))


def canonical_extent(data):
    """Remove zero alignment words only after a terminal + delay slot.

    Never remove a return's nop delay slot. Do not trim arbitrary trailing zeros.
    Boundary inference remains a documented limitation.
    """
    values = words(data)
    for index in range(len(values) - 2, -1, -1):
        value = values[index]
        terminal = value == 0x03E00008 or value >> 26 == 2
        if terminal and not any(values[index + 2:]):
            return data[:(index + 2) * 4]
    return data


def address_mask(data):
    """Mask direct jump addresses and adjacent absolute LUI/low pairs only.

    Branch displacements, registers, stack offsets, and other constants survive.
    This deliberately misses non-adjacent pairs rather than masking too broadly.
    """
    values = words(data)
    masked = list(values)
    edits = []
    for index, value in enumerate(values):
        opcode = value >> 26
        if opcode in (2, 3):
            masked[index] &= 0xFC000000
            edits.append(index * 4)
        if opcode != 15 or index + 1 >= len(values):
            continue
        register = (value >> 16) & 31
        low = values[index + 1]
        low_opcode = low >> 26
        if (low >> 21) & 31 != register:
            continue
        if low_opcode not in (9, 13, 32, 33, 35, 36, 37, 40, 41, 43, 49, 53, 57, 61):
            continue
        immediate = low & 0xFFFF
        if low_opcode != 13 and immediate & 0x8000:
            immediate -= 0x10000
        address = ((value & 0xFFFF) << 16) + immediate
        if not 0x80000000 <= address <= 0xBFFFFFFF:
            continue
        masked[index] &= 0xFFFF0000
        masked[index + 1] &= 0xFFFF0000
        edits.extend((index * 4, (index + 1) * 4))
    return struct.pack(f">{len(masked)}I", *masked), sorted(set(edits))


def donor_functions(repository, rom):
    segments = yaml.safe_load((repository / "yamls/us/rom.yaml").read_text())
    text = next(segment for segment in segments if segment.get("name") == "text")
    entries = text["subsegments"]
    symbols = defaultdict(set)
    for path in sorted((repository / "linker_scripts/us").glob("symbol_addrs*.txt")):
        for line in path.read_text().splitlines():
            match = SYMBOL.match(line)
            if match and ("type:func" in line or path.name == "symbol_addrs_ultralib.txt"):
                symbols[int(match[2], 16)].add(match[1])
    result = []
    omissions = []
    for index, entry in enumerate(entries[:-1]):
        if not isinstance(entry, list) or len(entry) < 2:
            continue
        start, kind = entry[:2]
        if not isinstance(start, int):
            continue
        label = str(entry[2]) if len(entry) > 2 else ""
        library = label if kind == "lib" else label.split("/")[0]
        if kind not in ("lib", "c", "hasm", "asm") or not library.startswith("lib"):
            continue
        if kind == "lib" and len(entry) > 4:
            continue  # data / rodata, never CPU functions
        following = entries[index + 1]
        end = following[0] if isinstance(following, list) else following["start"]
        base = text["vram"] - text["start"]
        points = sorted(address for address in symbols if start <= address - base < end)
        if not points:
            omissions.append({"module": entry, "reason": "no named function entry"})
        for point_index, address in enumerate(points):
            function_start = address - base
            function_end = points[point_index + 1] - base if point_index + 1 < len(points) else end
            payload = rom[function_start:function_end]
            result.append({
                "names": sorted(symbols[address]), "library": library,
                "module": "/".join(map(str, entry[2:])),
                "address": hex(address), "rom_start": hex(function_start),
                "extent": len(payload), "data": payload,
            })
    return result, omissions


def zero_functions(rom):
    inventory = json.loads((ROOT / "docs/pragma-inventory.json").read_text())
    manifest = json.loads((ROOT / "docs/mappings/resident-fragments.json").read_text())
    images = {}
    result = []
    for owner in inventory["owners"]:
        image_index = owner["image_index"]
        if image_index is None:
            image = rom
        else:
            if image_index not in images:
                images[image_index] = load_image(rom, manifest["fragments"][image_index])
            image = images[image_index]
        start, end = int(owner["start"], 0), int(owner["end"], 0)
        payload = image[start:end]
        if hashlib.sha256(payload).hexdigest() != owner["input_sha256"]:
            raise ValueError(f"owner input hash mismatch: {owner['name']}")
        result.append({
            "name": owner["name"], "source": owner["source"],
            "image_index": image_index, "start": owner["start"],
            "address": owner["link_start"], "data": payload,
            "aliases": owner["aliases"],
        })
    return result


def compare(donors, zero):
    indexes = [defaultdict(list) for _ in range(3)]
    for candidate in zero:
        data = candidate["data"]
        canonical = canonical_extent(data)
        signatures = (data, canonical, address_mask(canonical)[0])
        for index, signature in zip(indexes, signatures):
            index[signature].append(candidate)
    rows = []
    for donor in donors:
        data = donor["data"]
        canonical = canonical_extent(data)
        masked, edits = address_mask(canonical)
        found = False
        for tier, signature, index in zip(
                ("exact_extent", "exact_code_padding_only", "address_masked_candidate"),
                (data, canonical, masked), indexes):
            hits = index.get(signature, [])
            if not hits:
                continue
            found = True
            for hit in hits:
                rows.append({
                    "donor": donor["donor"], "library": donor["library"],
                    "module": donor["module"], "donor_names": ";".join(donor["names"]),
                    "donor_address": donor["address"], "donor_rom": donor["rom_start"],
                    "donor_extent": len(data), "code_bytes": len(canonical),
                    "tier": tier, "zero_owner": hit["name"], "zero_source": hit["source"],
                    "zero_image": hit["image_index"], "zero_address": hit["address"],
                    "zero_extent": len(hit["data"]), "masked_offsets": ";".join(map(hex, edits)),
                    "ambiguity": "multiple_zero_hits" if len(hits) > 1 else "",
                })
            break
        if not found:
            rows.append({
                "donor": donor["donor"], "library": donor["library"],
                "module": donor["module"], "donor_names": ";".join(donor["names"]),
                "donor_address": donor["address"], "donor_rom": donor["rom_start"],
                "donor_extent": len(data), "code_bytes": len(canonical), "tier": "no_hit",
            })
    return rows


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--stadium1-rom", type=Path, required=True)
    parser.add_argument("--stadium2-rom", type=Path, required=True)
    parser.add_argument("--zero-rom", type=Path, default=ROOT / "baseroms/jp/baserom.z64")
    parser.add_argument("--references", type=Path, default=ROOT / ".analysis/reference")
    parser.add_argument("--output", type=Path, default=ROOT / "docs/library-overlap")
    args = parser.parse_args()
    zero_rom = args.zero_rom.read_bytes()
    if hashlib.sha256(zero_rom).hexdigest() != EXPECTED_SHA256:
        raise ValueError("unexpected Zero ROM")
    zero = zero_functions(zero_rom)
    donors = []
    provenance = {}
    for name, (folder, expected_md5) in TARGETS.items():
        path = getattr(args, f"{name}_rom")
        data = path.read_bytes()
        if hashlib.md5(data).hexdigest() != expected_md5:
            raise ValueError(f"unexpected {name} ROM")
        repository = args.references / folder
        functions, omissions = donor_functions(repository, data)
        for function in functions:
            function["donor"] = name
        donors.extend(functions)
        revision = subprocess.check_output(
            ["git", "-C", str(repository), "rev-parse", "HEAD"], text=True).strip()
        provenance[name] = {
            "repository": f"https://github.com/michiiik/{folder}", "revision": revision,
            "rom_md5": expected_md5, "rom_sha256": hashlib.sha256(data).hexdigest(),
            "functions": len(functions), "modules_without_symbols": omissions,
        }
    rows = compare(donors, zero)
    args.output.mkdir(parents=True, exist_ok=True)
    fields = list(next(row for row in rows if row["tier"] != "no_hit"))
    with (args.output / "library-overlap.csv").open("w", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)
    summary = {
        "zero_input_sha256": EXPECTED_SHA256, "zero_owners": len(zero),
        "donors": provenance, "tier_counts": {},
        "scope": "whole_owner_extents_only; aliases_not_separately_split",
        "compiler_verification": "not_run",
    }
    for name in TARGETS:
        subset = [row for row in rows if row["donor"] == name]
        summary["tier_counts"][name] = {
            tier: len({row["donor_address"] for row in subset if row["tier"] == tier})
            for tier in ("exact_extent", "exact_code_padding_only", "address_masked_candidate", "no_hit")
        }
        summary.setdefault("unambiguous_at_least_32_bytes", {})[name] = dict(Counter(
            row["tier"] for row in subset if row["tier"] != "no_hit"
            and not row["ambiguity"] and row["code_bytes"] >= 32))
        by_library = {}
        for library in sorted({row["library"] for row in subset}):
            selected = [row for row in subset if row["library"] == library]
            by_library[library] = {
                tier: len({row["donor_address"] for row in selected if row["tier"] == tier})
                for tier in ("exact_extent", "exact_code_padding_only",
                             "address_masked_candidate", "no_hit")}
        summary.setdefault("by_library", {})[name] = by_library
    summary["unique_zero_hit_owners"] = len({
        row["zero_owner"] for row in rows if row["tier"] != "no_hit"})
    summary["unique_zero_exact_owners"] = len({
        row["zero_owner"] for row in rows if row["tier"].startswith("exact")})
    qualified = [row for row in rows if row["tier"] != "no_hit"
                 and not row["ambiguity"] and row["code_bytes"] >= 32]
    summary["qualified_unique_zero_owners"] = len({row["zero_owner"] for row in qualified})
    summary["qualified_unique_zero_exact_owners"] = len({
        row["zero_owner"] for row in qualified if row["tier"].startswith("exact")})
    summary["qualified_exact_code_bytes"] = sum({
        row["zero_owner"]: row["code_bytes"] for row in qualified
        if row["tier"].startswith("exact")}.values())
    (args.output / "summary.json").write_text(json.dumps(summary, indent=2) + "\n")
    print(json.dumps(summary, indent=2))


if __name__ == "__main__":
    main()
