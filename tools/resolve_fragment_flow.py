#!/usr/bin/env python3
"""Static indirect-table resolution and evidence-led text-gap validation.

Does not claim runtime callback values, immutable tables, or ABI-independent
function boundaries. All reports use restored-image offsets.
"""
import argparse
from collections import Counter
import csv
import hashlib
import json
from pathlib import Path

import rabbitizer

from map_fragment_sections import (base_address, executable_instruction, intervals,
                                   load_image, map_image, relocations, word)
from map_rom import EXPECTED_SHA256


def fields(value):
    return value >> 26, value >> 21 & 31, value >> 16 & 31, value >> 11 & 31, value & 63


def signed(value):
    value &= 0xFFFF
    return value - 0x10000 if value & 0x8000 else value


def writes(value, register):
    instruction = rabbitizer.Instruction(value)
    return ((instruction.modifiesRd() and (value >> 11 & 31) == register)
            or (instruction.modifiesRt() and (value >> 16 & 31) == register)
            or (instruction.modifiesRs() and (value >> 21 & 31) == register)
            or (instruction.doesLink() and register == 31 and value >> 26 != 0))


def code_words(report):
    return {position for start, end in report["instruction_ranges"]
            for position in range(int(start, 0), int(end, 0), 4)}


def reaches_clean(image, start, stop, register, base=0):
    """All bounded direct paths reaching stop retain register since start.

    Unlike a linear scan, bypassed register writes do not kill a definition.
    Calls conservatively kill the value. This only checks the inspected local
    subgraph, not possible runtime entry into its middle.
    """
    pending = [(start, True)]
    seen = set()
    arrivals = []
    while pending:
        position, clean = pending.pop()
        if position == stop:
            arrivals.append(clean)
            continue
        if not start <= position < stop or (position, clean) in seen:
            continue
        seen.add((position, clean))
        value = word(image, position)
        instruction = rabbitizer.Instruction(value, base + position)
        clean = clean and not writes(value, register)
        if instruction.hasDelaySlot():
            if position + 4 == stop:
                arrivals.append(clean)
                continue
            delay_clean = clean and not writes(word(image, position + 4), register)
            if instruction.isBranch():
                target = instruction.getBranchVramGeneric() - base
                pending.append((target, delay_clean))
                if not instruction.isUnconditionalBranch():
                    pending.append((position + 8,
                                    clean if instruction.isBranchLikely() else delay_clean))
            elif instruction.isJumpWithAddress():
                if instruction.doesLink():
                    pending.append((position + 8, False))
                else:
                    pending.append((instruction.getInstrIndexAsVram() - base, delay_clean))
            elif instruction.doesLink():
                pending.append((position + 8, False))
        else:
            pending.append((position + 4, clean))
    return bool(arrivals) and all(arrivals)


def standard_switch(image, metadata, site, text_end):
    """Accept only the exact LUI/ADDU/LW/JR pipeline with an inspected guard."""
    base = base_address(metadata)
    jump = word(image, site)
    op, target_register, _, _, function = fields(jump)
    if op != 0 or function != 8:
        return None
    load, add, high = [word(image, site - distance) for distance in (4, 8, 12)]
    load_op, address_register, load_target, _, _ = fields(load)
    add_op, add_left, add_right, add_target, add_function = fields(add)
    high_op, _, high_target, _, _ = fields(high)
    if not (load_op == 35 and load_target == target_register
            and add_op == 0 and add_function == 33 and add_target == address_register
            and high_op == 15 and high_target == address_register):
        return None
    if add_left == address_register:
        index_register = add_right
    elif add_right == address_register:
        index_register = add_left
    else:
        return None
    shift_site = None
    for position in range(site - 16, max(0x1C, site - 64), -4):
        value = word(image, position)
        op, _, source, destination, function = fields(value)
        if writes(value, index_register):
            if op == 0 and function == 0 and destination == index_register \
                    and (value >> 6 & 31) == 2:
                shift_site, source_register = position, source
            break
    if shift_site is None:
        return None
    guard = None
    for position in range(shift_site - 4, max(0x1C, shift_site - 128), -4):
        value = word(image, position)
        op, source, result_register, _, _ = fields(value)
        if op != 11 or source != source_register or not 0 < signed(value) <= 1024:
            continue
        # source must retain the bounded value until the index shift.
        if not reaches_clean(image, position + 4, shift_site, source_register, base):
            continue
        for branch in range(position + 4, min(shift_site + 4, position + 128), 4):
            branch_word = word(image, branch)
            branch_op, left, right, _, _ = fields(branch_word)
            if branch_op != 4 or {left, right} != {result_register, 0}:
                continue
            if not reaches_clean(image, position + 4, branch, result_register, base):
                continue
            default = branch + 4 + signed(branch_word) * 4
            if default <= site + 4 and default >= branch:
                continue
            if not 0x20 <= default < text_end or default % 4 \
                    or executable_instruction(word(image, default), base + default) is None:
                continue
            guard = {"bound_site": hex(position), "branch_site": hex(branch),
                     "default_target": hex(default), "entry_count": signed(value),
                     "source_register": source_register}
            break
        if guard:
            break
    if guard is None:
        return None
    address = ((high & 0xFFFF) << 16) + signed(load)
    table_start = address - base
    table_end = table_start + guard["entry_count"] * 4
    if table_start < text_end or table_end > word(image, 0x14) or table_start % 4:
        return None
    pointer_sites = {p for kind, p in relocations(image) if kind == 2}
    entries = []
    for position in range(table_start, table_end, 4):
        target = word(image, position) - base
        if position not in pointer_sites or not 0x20 <= target < text_end or target % 4:
            return None
        if executable_instruction(word(image, target), base + target) is None:
            return None
        entries.append(target)
    return {"status": "resolved_static_bounded_table", "site": hex(site),
            "transfer": "jump", "table_start": hex(table_start),
            "table_end": hex(table_end), "guard": guard,
            "targets": [hex(target) for target in entries],
            "runtime_contract": "stored table entries; runtime mutation not excluded"}


def inspected_dispatch(image, metadata, site, text_end):
    """Input-specific handwritten dispatches verified by focused disassembly.

    t7 is initialized to 81152780 at 17D9C/17DA0 and 187CC/18804.
    Byte loads or explicit masks bound each index. They are not generic
    pattern discoveries and must remain tied to this exact input image.
    """
    if int(metadata["rom_start"], 0) != 0x80C00:
        return None
    layouts = {
        0x18898: (0x52780, 256, "byte opcode load then shift-left-two"),
        0x1A390: (0x52B80, 256, "byte opcode load then shift-left-two"),
        0x1BB10: (0x540C0, 16, "AND 0xF then shift-left-two"),
        0x1BB28: (0x54080, 16, "AND 0xF then shift-left-two"),
        0x1BD50: (0x54100, 32, "AND 0xF8 then shift-right-one"),
    }
    if site not in layouts:
        return None
    start, count, contract = layouts[site]
    base = base_address(metadata)
    pointers = {p for kind, p in relocations(image) if kind == 2}
    entries = []
    for position in range(start, start + count * 4, 4):
        target = word(image, position) - base
        if position not in pointers or target % 4 or not 0x20 <= target < text_end:
            raise ValueError("inspected dispatcher table changed")
        entries.append(hex(target))
    return {"site": hex(site), "transfer": "jump",
            "status": "resolved_inspected_masked_table",
            "table_start": hex(start), "table_end": hex(start + count * 4),
            "targets": entries, "index_contract": contract,
            "runtime_contract": "inspected t7 base initialization; stored table entries"}


def inspected_links(image, metadata, site):
    """Inspected finite register-call sets, including resumable link protocols."""
    if int(metadata["rom_start"], 0) != 0x80C00:
        return None
    converters = []
    for start, end in [(0x18298, 0x183C4), (0x183C4, 0x184F0)]:
        converters.extend(position for position in range(start, end, 4)
                          if word(image, position) & 0xFC1FFFFF == 0x0000A809)
    # Mask above retains rd/funct but removes the source register; enforce ra.
    converters = [position for position in converters
                  if word(image, position) >> 21 & 31 == 31]
    unpackers = [position for position in range(0x1BF34, 0x1BF74, 4)
                 if word(image, position) == 0x03E01809]
    targets = None
    contract = None
    if site == 0x3CD8:
        targets = [0x3BB4, 0x3BD0, 0x3BEC, 0x3C34]
        contract = "four branch-selected constants in s3; inspected comparators preserve s3"
    elif site == 0x18594:
        targets = [0x18298, 0x183C4, *(position + 8 for position in converters)]
        contract = "s5 converter entry or resume PC; jalr s5,ra supplies resume PCs"
    elif site in converters:
        targets = [0x1859C]
        contract = "ra initialized by jalr at 18594; writes next converter resume PC into s5"
    elif site == 0x1BF0C:
        targets = [0x1BF34, *(position + 8 for position in unpackers)]
        contract = "v1 unpacker entry or resume PC; jalr v1,ra supplies resume PCs"
    elif site in unpackers:
        targets = [0x1BF14]
        contract = "ra initialized by jalr at 1BF0C; writes next unpacker resume PC into v1"
    if targets is None:
        return None
    for target in targets:
        if executable_instruction(word(image, target), base_address(metadata) + target) is None:
            raise ValueError("inspected link target changed")
    return {"site": hex(site), "transfer": "call",
            "status": "resolved_inspected_register_protocol",
            "targets": [hex(target) for target in targets],
            "runtime_contract": contract + "; requires entry through the inspected protocol"}


def context_candidates(image, metadata, site, text_end):
    """Describe known initializer sets, never claim them runtime-exhaustive."""
    if int(metadata["rom_start"], 0) != 0x80C00:
        return None
    origin = local_origin(image, site)
    if origin.get("memory_base_register") != 1 or origin.get("memory_displacement") != 0x5C00:
        return None
    known = {}
    for position in range(0x17DE0, 0x18004, 4):
        value = word(image, position)
        op, base_register, source_register, _, _ = fields(value)
        displacement = signed(value)
        if op != 43 or base_register != 30 or not 0x5C00 <= displacement < 0x5D00:
            continue
        high_value = None
        low_value = None
        for earlier in range(position - 4, max(0x17D7C, position - 512), -4):
            prior = word(image, earlier)
            if not writes(prior, source_register):
                continue
            prior_op, source, destination, _, _ = fields(prior)
            if low_value is None and prior_op == 9 and source == destination == source_register:
                low_value = signed(prior)
            elif low_value is not None and prior_op == 15 and destination == source_register:
                high_value = (prior & 0xFFFF) << 16
                break
            else:
                break
        if high_value is not None:
            target = high_value + low_value - base_address(metadata)
            if not 0x20 <= target < text_end:
                raise ValueError("initializer target outside candidate text")
            known.setdefault(target, []).append(hex(position))
    return {"site": hex(site), "transfer": "call",
            "status": "known_initializer_candidates_runtime_unresolved",
            "targets": [hex(target) for target in sorted(known)],
            "initialization_stores": {hex(target): stores for target, stores in sorted(known.items())},
            "runtime_contract": "requires initialized context and excludes unknown alias writes",
            **{key: value for key, value in origin.items() if key != "status"}}


def local_origin(image, site):
    """Find the nearest target-register writer without crossing a call.

    Branches are recorded as ambiguity, not silently treated as straight-line
    dominance. This is provenance evidence, never a substitute for CFG dataflow.
    """
    _, register, _, link_register, function = fields(word(image, site))
    branches = []
    for position in range(site - 4, max(0x1C, site - 256), -4):
        value = word(image, position)
        instruction = rabbitizer.Instruction(value)
        if instruction.doesLink():
            return {"status": "runtime_target_unresolved", "reason": "prior_call_boundary",
                    "source_register": register, "link_register": link_register
                    if function == 9 else None, "boundary": hex(position)}
        if instruction.hasDelaySlot():
            branches.append(hex(position))
        if writes(value, register):
            op, source, _, _, _ = fields(value)
            return {"status": "runtime_target_unresolved", "source_register": register,
                    "link_register": link_register if function == 9 else None,
                    "writer_site": hex(position),
                    "writer_instruction": instruction.disassemble(),
                    "origin": "memory_load" if op == 35 else "register_computation",
                    "memory_base_register": source if op == 35 else None,
                    "memory_displacement": signed(value) if op == 35 else None,
                    "intervening_control_transfers": branches,
                    "reason": "local writer is not proof of all-path dominance"}
    return {"status": "runtime_target_unresolved", "source_register": register,
            "link_register": link_register if function == 9 else None,
            "reason": "no writer in bounded backward window"}


def constant_call(image, metadata, site):
    """Resolve LUI + ADDIU into a local JALR target without intervening calls.

    Branches between the definition and site are rejected here, deliberately
    avoiding a linear-scan-as-dominance claim.
    """
    _, register, _, _, function = fields(word(image, site))
    if function != 9:
        return None
    origin = local_origin(image, site)
    if origin.get("intervening_control_transfers") or "writer_site" not in origin:
        return None
    position = int(origin["writer_site"], 0)
    value = word(image, position)
    op, source, destination, _, _ = fields(value)
    if op != 9 or source != register or destination != register:
        return None
    high = word(image, position - 4)
    if high >> 26 != 15 or high >> 16 & 31 != register:
        return None
    target = (((high & 0xFFFF) << 16) + signed(value)) - base_address(metadata)
    if not 0x20 <= target < word(image, 0x14) or target % 4:
        return None
    return {"status": "resolved_local_constant_call", "site": hex(site),
            "transfer": "call", "targets": [hex(target)],
            "definition_sites": [hex(position - 4), hex(position)]}


def structural_check(image, metadata, start, stop, text_end):
    """Check candidate structure without treating valid encodings as execution."""
    base = base_address(metadata)
    failures = []
    transfers = []
    for position in range(start, stop, 4):
        instruction = executable_instruction(word(image, position), base + position)
        if instruction is None:
            failures.append({"site": hex(position), "reason": "invalid_or_trap_encoding"})
            continue
        if instruction.hasDelaySlot():
            delay = position + 4
            if delay + 4 > text_end:
                failures.append({"site": hex(position), "reason": "delay_beyond_text"})
            else:
                delay_instruction = executable_instruction(word(image, delay), base + delay)
                if delay_instruction is None or delay_instruction.hasDelaySlot():
                    failures.append({"site": hex(position), "reason": "invalid_delay_slot"})
        if instruction.isBranch():
            target = instruction.getBranchVramGeneric() - base
            transfers.append({"site": hex(position), "kind": "branch", "target_offset": hex(target)})
            if not 0x20 <= target < text_end or target % 4:
                failures.append({"site": hex(position), "reason": "branch_outside_text"})
        elif instruction.isJumpWithAddress():
            target = instruction.getInstrIndexAsVram()
            transfers.append({"site": hex(position), "kind": "direct_jump_or_call",
                              "target_vram": hex(target)})
    return {"status": "passed_structure_reachability_unproven" if not failures else "failed",
            "failures": failures, "control_transfers": transfers}


def validate_image(image, metadata, external_seeds=None):
    initial = map_image(image, metadata)
    if initial["text_envelope"] is None:
        return initial, {"transfers": [], "gaps": [], "new_instruction_bytes": 0}
    text_end = int(initial["text_envelope"][1], 0)
    edges = {}
    resolved = {}
    seeds = dict(external_seeds or {})
    report = initial
    for _ in range(16):
        before = code_words(report)
        # A relocated pointer into the already checked candidate prefix gives
        # an additional reference-backed entry hypothesis. It must still pass
        # traversal/range checks; arbitrary pointers into resource data remain
        # excluded. This is static code evidence, not observed execution.
        proposed = dict(seeds)
        for kind, position in relocations(image):
            target = word(image, position) - base_address(metadata) if kind == 2 else -1
            if 0x20 <= target < text_end and target % 4 == 0 and target not in before:
                proposed[target] = "relocated_pointer_into_checked_text_prefix"
        if proposed != seeds:
            trial = map_image(image, metadata, proposed, edges)
            added = code_words(trial) - before
            if not trial["rejected"] and all(0x20 <= p < text_end for p in added):
                seeds = proposed
                report = trial
        for site_hex in report["unresolved_indirect_jumps"]:
            site = int(site_hex, 0)
            resolution = standard_switch(image, metadata, site, text_end) \
                or inspected_dispatch(image, metadata, site, text_end) \
                or inspected_links(image, metadata, site) \
                or constant_call(image, metadata, site) \
                or context_candidates(image, metadata, site, text_end)
            if resolution:
                resolved[site] = resolution
                edges[site] = [int(target, 0) for target in resolution["targets"]]
        # The body prefix itself is already a candidate. A stack-adjusting
        # prologue is evidence of a missed entry, but only promote its reachable
        # words after checking traversal never escapes the candidate prefix.
        for section in report["sections"]:
            if section["kind"] != "cpu_instruction_candidate":
                continue
            for start in range(int(section["start"], 0), int(section["end"], 0), 4):
                value = word(image, start)
                if value & 0xFFFF0000 != 0x27BD0000 or not value & 0x8000:
                    continue
                trial = map_image(image, metadata, {**seeds, start: "candidate_gap_stack_prologue"},
                                  edges)
                added = code_words(trial) - before
                if not trial["rejected"] and all(0x20 <= p < text_end for p in added):
                    seeds[start] = "validated_gap_stack_prologue_traversal"
        report = map_image(image, metadata, seeds, edges)
        if code_words(report) == before:
            break
    else:
        raise ValueError("resolution did not converge")
    transfers = []
    for site_hex in sorted(report["unresolved_indirect_jumps"], key=lambda value: int(value, 0)):
        site = int(site_hex, 0)
        transfer = resolved.get(site)
        if transfer is None:
            transfer = context_candidates(image, metadata, site, text_end) or {"site": site_hex,
                        "transfer": "call" if word(image, site) & 63 == 9 else "jump",
                        **local_origin(image, site)}
        transfers.append(transfer)
    original = code_words(initial)
    final = code_words(report)
    gaps = []
    for section in initial["sections"]:
        if section["kind"] not in ("cpu_instruction_candidate", "zero_fill_candidate"):
            continue
        start, stop = int(section["start"], 0), int(section["end"], 0)
        for category, positions in [
            ("validated_by_new_flow", set(range(start, stop, 4)) & final),
            ("remaining_zero_unproven", {p for p in range(start, stop, 4)
                                       if p not in final and word(image, p) == 0}),
            ("remaining_instruction_candidate", {p for p in range(start, stop, 4)
                                                if p not in final and word(image, p) != 0}),
        ]:
            for left, right in intervals(positions):
                row = {"start": hex(left), "end": hex(right), "status": category}
                if category == "remaining_instruction_candidate":
                    row["structural_validation"] = structural_check(
                        image, metadata, left, right, text_end)
                gaps.append(row)
    report["unresolved_indirect_jumps"] = [row["site"] for row in transfers
                                          if "runtime_unresolved" in row["status"]
                                          or row["status"] == "runtime_target_unresolved"]
    return report, {"transfers": transfers, "gaps": sorted(gaps, key=lambda row: int(row["start"], 0)),
                    "new_entry_seeds": {hex(p): reason for p, reason in sorted(seeds.items())},
                    "new_instruction_bytes": (len(final) - len(original)) * 4}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument("--manifest", type=Path,
                        default=Path("docs/mappings/resident-fragments.json"))
    parser.add_argument("--output-dir", type=Path, default=Path("docs/sections/refined"))
    args = parser.parse_args()
    rom = args.rom.read_bytes()
    if hashlib.sha256(rom).hexdigest() != EXPECTED_SHA256:
        raise ValueError("wrong ROM")
    metadata = json.loads(args.manifest.read_text())["fragments"]
    reports, flow = [], []
    images = [load_image(rom, item) for item in metadata]
    external_seeds = [{} for _ in metadata]
    cross_edges = {}
    slots = {}
    for index, item in enumerate(metadata):
        slots.setdefault(base_address(item), []).append(index)
    for _ in range(8):
        reports, flow = [], []
        for index, item in enumerate(metadata):
            report, detail = validate_image(images[index], item, external_seeds[index])
            report["image_index"] = index
            detail["image_index"] = index
            detail["link_base"] = item["link_base"]
            reports.append(report)
            flow.append(detail)
        changed = False
        known_code = [code_words(report) for report in reports]
        for source_index, report in enumerate(reports):
            for position in sorted(code_words(report)):
                instruction = rabbitizer.Instruction(word(images[source_index], position),
                                                     base_address(metadata[source_index]) + position)
                if not instruction.isJumpWithAddress():
                    continue
                target = instruction.getInstrIndexAsVram()
                target_slot = target & 0xFFF00000
                if target_slot == base_address(metadata[source_index]) or target_slot not in slots:
                    continue
                candidates = slots[target_slot]
                key = (source_index, position)
                cross_edges[key] = {"source_image": source_index, "source_offset": hex(position),
                                    "target_vram": hex(target), "candidate_images": candidates,
                                    "status": "ambiguous_reused_slot" if len(candidates) != 1
                                    else "unique_image_slot"}
                if len(candidates) != 1:
                    continue
                target_index = candidates[0]
                target_offset = target - target_slot
                envelope = reports[target_index]["text_envelope"]
                if target_offset == 0:
                    target_offset = int(metadata[target_index]["entry_offset"], 0)
                if envelope and 0x20 <= target_offset < int(envelope[1], 0) \
                        and target_offset % 4 == 0 and target_offset not in known_code[target_index] \
                        and target_offset not in external_seeds[target_index]:
                    external_seeds[target_index][target_offset] = \
                        f"cross_fragment_direct_reference_from_image_{source_index}_{position:X}"
                    changed = True
        if not changed:
            break
    else:
        raise ValueError("cross-fragment propagation did not converge")
    statuses = Counter(row["status"] for detail in flow for row in detail["transfers"])
    gaps = Counter()
    for detail in flow:
        for row in detail["gaps"]:
            gaps[row["status"]] += int(row["end"], 0) - int(row["start"], 0)
    summary = {"image_count": len(reports), "transfer_status_counts": dict(statuses),
               "gap_bytes": dict(gaps),
               "instruction_evidence_bytes": sum(row["instruction_bytes"] for row in reports),
               "rejected_paths": sum(len(row["rejected"]) for row in reports),
               "cross_fragment_entry_seeds": sum(len(seeds) for seeds in external_seeds),
               "remaining_gap_structural_failures": sum(
                   len(row.get("structural_validation", {}).get("failures", []))
                   for detail in flow for row in detail["gaps"])}
    args.output_dir.mkdir(parents=True, exist_ok=True)
    for name, content in [("fragment-sections.json", {"summary": summary, "images": reports}),
                          ("flow-validation.json", {"summary": summary, "images": flow}),
                          ("cross-fragment-edges.json", {"edges": list(cross_edges.values())})]:
        (args.output_dir / name).write_text(json.dumps(content, indent=2) + "\n")
    with (args.output_dir / "indirect-transfers.csv").open("w", newline="") as output:
        writer = csv.writer(output)
        writer.writerow(["image_index", "link_base", "site", "transfer", "status",
                         "table_start", "target_count", "origin", "writer_site"])
        for detail in flow:
            for row in detail["transfers"]:
                writer.writerow([detail["image_index"], detail["link_base"], row["site"],
                                 row["transfer"], row["status"], row.get("table_start", ""),
                                 len(row.get("targets", [])), row.get("origin", ""),
                                 row.get("writer_site", "")])
    with (args.output_dir / "text-gap-validation.csv").open("w", newline="") as output:
        writer = csv.writer(output)
        writer.writerow(["image_index", "start", "end_exclusive", "bytes", "status",
                         "structural_validation", "structural_failures"])
        for detail in flow:
            for row in detail["gaps"]:
                check = row.get("structural_validation", {})
                writer.writerow([detail["image_index"], row["start"], row["end"],
                                 int(row["end"], 0) - int(row["start"], 0), row["status"],
                                 check.get("status", ""), len(check.get("failures", []))])
    with (args.output_dir / "fragment-sections.csv").open("w", newline="") as output:
        writer = csv.writer(output)
        writer.writerow(["image_index", "rom_start", "storage", "link_base", "classification",
                         "text_start", "text_end_exclusive", "instruction_evidence_bytes",
                         "unresolved_indirect_transfers", "rejected_paths"])
        for report in reports:
            writer.writerow([report["image_index"], report["rom_start"], report["storage"],
                             report["link_base"], report["classification"],
                             *(report["text_envelope"] or ["", ""]), report["instruction_bytes"],
                             len(report["unresolved_indirect_jumps"]), len(report["rejected"])])
    with (args.output_dir / "runtime-watchlist.csv").open("w", newline="") as output:
        writer = csv.writer(output)
        writer.writerow(["image_index", "link_base", "offset", "link_time_pc",
                         "target_register_number", "link_register_number", "status",
                         "memory_base_register_number", "memory_displacement",
                         "known_candidate_offsets", "runtime_contract"])
        for detail in flow:
            for row in detail["transfers"]:
                if row["status"] not in ("runtime_target_unresolved",
                                         "known_initializer_candidates_runtime_unresolved"):
                    continue
                writer.writerow([detail["image_index"], detail["link_base"], row["site"],
                                 hex(int(detail["link_base"], 0) + int(row["site"], 0)),
                                 row.get("source_register", ""), row.get("link_register", ""),
                                 row["status"], row.get("memory_base_register", ""),
                                 row.get("memory_displacement", ""),
                                 ";".join(row.get("targets", [])),
                                 row.get("runtime_contract", row.get("reason", ""))])
    print(json.dumps(summary, indent=2))


if __name__ == "__main__":
    main()
