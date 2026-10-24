#!/usr/bin/env python3
"""Fresh-build a bounded donor library batch and verify raw function bytes.

No source integration, address masking, or full-ROM build is performed.
"""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import subprocess

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

from compare_library_overlap import canonical_extent
from map_rom import EXPECTED_SHA256

ROOT = Path(__file__).resolve().parents[1]
REVISION = "61ab5896988e55a1355dcaae7c4302785ea97f21"
BATCH = {
    "libc/string": ("memcpy", "strlen", "strchr"),
    "libc/ldiv": ("ldiv",),
    "gu/mtxutil": ("guMtxF2L", "guMtxIdentF", "guMtxL2F"),
    "gu/mtxcatf": ("guMtxCatF", "guMtxXFMF"),
}


def digest(data):
    return hashlib.sha256(data).hexdigest()


def log_text(value):
    """Keep diagnostic contents, normalize display-only line-end whitespace."""
    return "\n".join(line.rstrip() for line in value.splitlines()) + "\n"


def compare_bytes(actual, expected):
    return {
        "byte_identical": actual == expected,
        "actual_size": len(actual), "expected_size": len(expected),
        "mismatched_word_offsets": [
            hex(offset) for offset in range(0, max(len(actual), len(expected)), 4)
            if actual[offset:offset + 4] != expected[offset:offset + 4]],
    }


def functions_in_object(path):
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        if elf.little_endian or elf.elfclass != 32 or elf["e_machine"] != "EM_MIPS":
            raise ValueError("expected big-endian ELF32 MIPS")
        symbols = elf.get_section_by_name(".symtab")
        result = {}
        for symbol in symbols.iter_symbols():
            if symbol["st_info"]["type"] != "STT_FUNC":
                continue
            index = symbol["st_shndx"]
            if not isinstance(index, int):
                continue
            section = elf.get_section(index)
            start, size = symbol["st_value"], symbol["st_size"]
            if not size or section.name != ".text":
                raise ValueError(f"missing function extent: {symbol.name}")
            relocations = []
            for candidate in elf.iter_sections():
                if not isinstance(candidate, RelocationSection) or candidate["sh_info"] != index:
                    continue
                for relocation in candidate.iter_relocations():
                    if start <= relocation["r_offset"] < start + size:
                        relocations.append(dict(relocation.entry))
            result[symbol.name] = (section.data()[start:start + size], relocations)
        return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--stadium1-rom", type=Path, required=True)
    parser.add_argument("--zero-rom", type=Path, default=ROOT / "baseroms/jp/baserom.z64")
    parser.add_argument("--repository", type=Path,
                        default=ROOT / ".analysis/reference/pokestadium")
    parser.add_argument("--output", type=Path,
                        default=ROOT / "docs/library-overlap/compiler-test")
    parser.add_argument("--candidate-sources", type=Path,
                        default=ROOT / "candidates/libraries/batch1")
    args = parser.parse_args()
    repository = args.repository.resolve()
    revision = subprocess.check_output(
        ["git", "-C", str(repository), "rev-parse", "HEAD"], text=True).strip()
    if revision != REVISION:
        raise ValueError("unexpected donor revision")
    tracked_diff = subprocess.check_output(
        ["git", "-C", str(repository), "diff", "HEAD", "--",
         "lib/ultralib", "tools/ido/linux/5.3"])
    if tracked_diff:
        raise ValueError("modified donor source/toolchain")
    donor_rom = args.stadium1_rom.read_bytes()
    zero_rom = args.zero_rom.read_bytes()
    if hashlib.md5(donor_rom).hexdigest() != "ed1378bc12115f71209a77844965ba50":
        raise ValueError("unexpected donor ROM")
    if digest(zero_rom) != EXPECTED_SHA256:
        raise ValueError("unexpected Zero ROM")
    library = repository / "lib/ultralib"
    candidate_hashes = {}
    for module in BATCH:
        candidate = args.candidate_sources / f"{module}.c"
        source = library / f"src/{module}.c"
        if candidate.read_bytes() != source.read_bytes():
            raise ValueError(f"candidate differs from tested donor TU: {module}")
        candidate_hashes[module] = digest(candidate.read_bytes())
    output = args.output.resolve()
    evidence = output / "evidence"
    evidence.mkdir(parents=True, exist_ok=True)
    command = [
        "make", "-B", "VERSION=I_P", "TARGET=libultra_rom", "FIXUPS=1",
        "COMPARE=0", "CROSS=mips-linux-gnu-", "CC=../../tools/ido/linux/5.3/cc",
        "VERBOSE=1", "COLOR=0",
        *(f"build/I_P/libultra_rom/src/{module}.marker" for module in BATCH),
    ]
    completed = subprocess.run(command, cwd=library, text=True,
                               stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    (evidence / "build.txt").write_text(log_text(completed.stdout))
    if completed.returncode:
        raise RuntimeError(f"production recipe failed: inspect {evidence / 'build.txt'}")
    with (ROOT / "docs/library-overlap/library-overlap.csv").open() as stream:
        overlap = list(csv.DictReader(stream))
    rows = []
    source_hashes = {}
    object_hashes = {}
    for module, names in BATCH.items():
        source_hashes[module] = digest((library / f"src/{module}.c").read_bytes())
        path = library / f"build/I_P/libultra_rom/src/{module}.o"
        object_hashes[module] = digest(path.read_bytes())
        object_functions = functions_in_object(path)
        disassembly = subprocess.check_output(
            ["mips-linux-gnu-objdump", "-drz", "-Mreg-names=32", "-Mno-aliases", str(path)],
            text=True)
        (evidence / (module.replace("/", "_") + ".disasm.txt")).write_text(log_text(disassembly))
        for name in names:
            hits = [row for row in overlap if row["donor"] == "stadium1"
                    and name in row["donor_names"].split(";")
                    and row["tier"].startswith("exact") and not row["ambiguity"]]
            if len(hits) != 1:
                raise ValueError(f"expected one prior exact hit: {name}")
            hit = hits[0]
            data, relocations = object_functions[name]
            if relocations:
                raise ValueError(f"relocation-free contract violated: {name}")
            donor_start = int(hit["donor_rom"], 0)
            donor_extent = donor_rom[donor_start:donor_start + int(hit["donor_extent"])]
            donor_code = canonical_extent(donor_extent)
            zero_start = int(hit["zero_address"], 0) - 0x80000400 + 0x1000
            zero_extent = zero_rom[zero_start:zero_start + int(hit["zero_extent"])]
            if hit["zero_image"]:
                raise ValueError("selected target must be resident")
            zero_code = canonical_extent(zero_extent)
            donor_comparison = compare_bytes(data, donor_code)
            zero_comparison = compare_bytes(data, zero_code)
            rows.append({
                "function": name, "source": f"lib/ultralib/src/{module}.c",
                "zero_owner": hit["zero_owner"], "zero_address": hit["zero_address"],
                "object_function_bytes": len(data), "function_relocations": len(relocations),
                "donor_control": donor_comparison, "zero_result": zero_comparison,
                "object_function_sha256": digest(data),
                "donor_code_sha256": digest(donor_code), "zero_code_sha256": digest(zero_code),
                "zero_extent_bytes": len(zero_extent), "donor_extent_bytes": len(donor_extent),
            })
    compiler = repository / "tools/ido/linux/5.3"
    summary = {
        "contract": "fresh-production-recipe-objects; raw STT_FUNC bytes; no relocations or masks",
        "repository": "https://github.com/michiiik/pokestadium",
        "revision": revision, "compiler": "donor-bundled IDO 5.3",
        "compiler_hashes": {name: digest((compiler / name).read_bytes())
                            for name in ("cc", "cfe", "uopt", "ugen", "as0", "as1")},
        "source_hashes": source_hashes, "object_hashes": object_hashes,
        "candidate_source_hashes": candidate_hashes,
        "candidate_source_contract": "byte-for-byte identical to compiled donor translation units",
        "make_command": command,
        "binutils": subprocess.check_output(["mips-linux-gnu-objdump", "--version"],
                                           text=True).splitlines()[0],
        "zero_rom_sha256": digest(zero_rom), "donor_rom_sha256": digest(donor_rom),
        "results": rows,
        "donor_controls_passed": sum(row["donor_control"]["byte_identical"] for row in rows),
        "zero_raw_matches": sum(row["zero_result"]["byte_identical"] for row in rows),
        "functions_tested": len(rows),
        "source_integration": "not_performed", "full_rom_baseline": "not_run",
        "zero_compiler_identity": "not_established",
    }
    (output / "results.json").write_text(json.dumps(summary, indent=2) + "\n")
    print(json.dumps(summary, indent=2))
    if any(not row["donor_control"]["byte_identical"]
           or not row["zero_result"]["byte_identical"] for row in rows):
        raise SystemExit(1)


if __name__ == "__main__":
    main()
