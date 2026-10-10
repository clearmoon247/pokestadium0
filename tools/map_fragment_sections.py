#!/usr/bin/env python3
"""Conservative, relocation-guided executable mapping for Stadium Zero images."""
import argparse
from collections import Counter, deque
import csv
import hashlib
import json
import struct
from pathlib import Path

import rabbitizer

from map_rom import EXPECTED_SHA256, inspect_fragment, trace_yay0


def word(data, offset):
    return struct.unpack_from(">I", data, offset)[0]


def load_image(rom, metadata):
    start = int(metadata["rom_start"], 0)
    size = int(metadata["image_size"], 0)
    if metadata["storage"] == "raw":
        image = rom[start:start + size]
    else:
        offset, decoded_size, _, count = struct.unpack_from(">4I", rom, start + 8)
        decoded, _ = trace_yay0(rom[start + offset:])
        if len(decoded) != decoded_size:
            raise ValueError("decoded size mismatch")
        restored = bytearray(decoded)
        for index in range(count):
            value, position = struct.unpack_from(">2I", rom, start + 24 + index * 8)
            struct.pack_into(">I", restored, position, value)
        image = bytes(restored)
    if hashlib.sha256(image).hexdigest() != metadata["decoded_sha256"]:
        raise ValueError("image differs from previously validated manifest")
    inspect_fragment(image)
    return image


def relocations(image):
    start = word(image, 0x14)
    count = word(image, start)
    return [(((value >> 24) & 0x7F), value & 0xFFFFFF)
            for value in struct.unpack_from(f">{count}I", image, start + 4)]


def intervals(offsets):
    result = []
    for offset in sorted(offsets):
        if result and result[-1][1] == offset:
            result[-1][1] += 4
        else:
            result.append([offset, offset + 4])
    return result


def executable_instruction(value, vram):
    instruction = rabbitizer.Instruction(value, vram)
    # RSP vector instructions, malformed encodings and traps are not promoted
    # to normal CPU code without specific evidence.
    return instruction if instruction.isValid() and not instruction.isTrap() else None


def map_image(image, metadata, extra_seeds=None, indirect_targets=None):
    base = int(metadata["link_base"], 0)
    end = word(image, 0x14)
    entry = int(metadata["entry_offset"], 0)
    records = relocations(image)
    instruction_sites = [(kind, position) for kind, position in records
                         if kind in (4, 5, 6) and position >= 0x20]
    # Header J is also present on non-executable resource fragments. A header
    # alone is not a CPU-code seed. Five no-relocation leaf wrappers have a
    # stack prologue; require that shape rather than accepting arbitrary words.
    entry_word = word(image, entry)
    stack_prologue = (entry_word & 0xFFFF0000) == 0x27BD0000 and bool(entry_word & 0x8000)
    seeds = {entry: {"header_target_with_body_instruction_relocations"
                     if instruction_sites else "header_target_stack_prologue"}} \
        if instruction_sites or stack_prologue else {}
    pointers = []
    for kind, position in records:
        if kind in (4, 5, 6) and position >= 0x20:
            # A relocation in a delay slot must not independently fall through
            # after its owner's unconditional jump or return.
            owner = position
            if position >= 0x24:
                previous = executable_instruction(word(image, position - 4), base + position - 4)
                if previous is not None and previous.hasDelaySlot():
                    owner -= 4
            seeds.setdefault(owner, set()).add(f"relocation_type_{kind}_site")
        if kind == 2:
            target = word(image, position) - base
            if 0x20 <= target < end and target % 4 == 0:
                pointers.append((position, target))
    # Inspected branch-free/leaf dispatch handlers after the final relocation
    # in the 811 slot. Their raw disassembly is retained in the evidence log.
    if int(metadata["rom_start"], 0) == 0x80C00:
        for position in (0x1C43C, 0x1C460, 0x1C468, 0x1C494):
            seeds.setdefault(position, set()).add("manually_inspected_tail_handler")
    for position, reason in (extra_seeds or {}).items():
        seeds.setdefault(position, set()).add(reason)
    code = set()
    processed = set()
    rejected = {}
    pending = deque(sorted(seeds))
    branch_edges = []
    calls = []
    indirect = []
    while pending:
        position = pending.popleft()
        if position in processed or position in rejected:
            continue
        if position < 0x20 or position + 4 > end or position % 4:
            rejected[position] = "out_of_payload"
            continue
        instruction = executable_instruction(word(image, position), base + position)
        if instruction is None:
            rejected[position] = "invalid_or_trap_instruction"
            continue
        code.add(position)
        processed.add(position)
        if instruction.hasDelaySlot():
            delay = position + 4
            if delay + 4 > end:
                rejected[delay] = "delay_slot_out_of_payload"
                continue
            delay_instruction = executable_instruction(word(image, delay), base + delay)
            if delay_instruction is None or delay_instruction.hasDelaySlot():
                rejected[delay] = "invalid_delay_slot"
                continue
            code.add(delay)
        if instruction.isJumpWithAddress():
            target = instruction.getInstrIndexAsVram() - base
            if 0x20 <= target < end:
                pending.append(target)
                seeds.setdefault(target, set()).add(
                    "direct_call_target" if instruction.doesLink() else "direct_jump_target")
            if instruction.doesLink():
                calls.append([position, target])
                pending.append(position + 8)
            else:
                branch_edges.append([position, target])
        elif instruction.isBranch():
            target = instruction.getBranchVramGeneric() - base
            pending.append(target)
            branch_edges.append([position, target])
            if not instruction.isUnconditionalBranch() or instruction.doesLink():
                pending.append(position + 8)
        elif instruction.isJump():
            if instruction.doesLink():
                pending.append(position + 8)
            # jalr using $ra as its SOURCE still transfers control and writes
            # another link register; it is not the ordinary jr $ra return.
            if not instruction.isJrRa() or instruction.doesLink():
                indirect.append(position)
            for target in (indirect_targets or {}).get(position, ()):
                pending.append(target)
                seeds.setdefault(target, set()).add("validated_indirect_table_target")
        else:
            pending.append(position + 4)
    # Candidate text envelope is deliberately distinct from CFG-established
    # words. Valid MIPS encodings alone never establish code.
    stop = max(code) + 4 if code else 0x20
    prefix = set(range(0x20, stop, 4))
    gaps = prefix - code
    invalid_gaps = [position for position in sorted(gaps)
                    if executable_instruction(word(image, position), base + position) is None]
    data_sites_in_prefix = [position for kind, position in records
                           if kind == 2 and 0x20 <= position < stop]
    candidate_prefix = bool(code) and not invalid_gaps and not data_sites_in_prefix
    labels = {}
    for position in range(0x20, end, 4):
        if position in code:
            labels[position] = "cpu_instruction_evidence"
        elif candidate_prefix and position < stop:
            labels[position] = "zero_fill_candidate" if word(image, position) == 0 \
                else "cpu_instruction_candidate"
        else:
            labels[position] = "unclassified_payload"
    # Include only zero words up to the next 16-byte boundary as a separately
    # labelled candidate alignment region, not executable instructions.
    aligned_stop = min((stop + 15) & ~15, end)
    if code and all(word(image, position) == 0 for position in range(stop, aligned_stop, 4)):
        for position in range(stop, aligned_stop, 4):
            labels[position] = "zero_alignment_candidate"
    sections = [{"kind": "fragment_header", "start": "0x0", "end": "0x20"}]
    for position, label in sorted(labels.items()):
        if sections[-1]["kind"] == label and int(sections[-1]["end"], 0) == position:
            sections[-1]["end"] = f"0x{position+4:X}"
        else:
            sections.append({"kind": label, "start": f"0x{position:X}",
                             "end": f"0x{position+4:X}"})
    sections.append({"kind": "relocation_table_and_storage_tail",
                     "start": f"0x{end:X}", "end": f"0x{len(image):X}"})
    pointer_targets = Counter(target for _, target in pointers)
    return {
        "rom_start": metadata["rom_start"], "storage": metadata["storage"],
        "link_base": metadata["link_base"], "decoded_sha256": metadata["decoded_sha256"],
        "entry_offset": f"0x{entry:X}", "payload_end": f"0x{end:X}",
        "instruction_ranges": [[f"0x{start:X}", f"0x{stop:X}"]
                               for start, stop in intervals(code)],
        "instruction_bytes": len(code) * 4,
        "relocation_instruction_seed_count": sum(
            any(reason.startswith("relocation_") for reason in reasons)
            for reasons in seeds.values()),
        "seed_reasons": {f"0x{position:X}": sorted(reasons)
                        for position, reasons in sorted(seeds.items())},
        "rejected": {f"0x{position:X}": reason for position, reason in sorted(rejected.items())},
        "unresolved_indirect_jumps": [f"0x{position:X}" for position in indirect],
        "data_pointer_targets_not_traversed": [
            {"target": f"0x{target:X}", "references": count,
             "already_code": target in code}
            for target, count in sorted(pointer_targets.items())
        ],
        "code_envelope_end": f"0x{max(code)+4:X}" if code else None,
        "direct_branch_count": len(branch_edges), "direct_call_count": len(calls),
        "classification": "cpu_code_present" if code else "no_cpu_code_evidence",
        "text_envelope": ["0x20", f"0x{stop:X}"] if candidate_prefix else None,
        "text_envelope_status": "inferred_contiguous_text_not_function_inventory"
            if candidate_prefix else "not_established",
        "invalid_words_in_envelope_gaps": [f"0x{position:X}" for position in invalid_gaps],
        "data_relocation_sites_in_envelope": [f"0x{position:X}" for position in data_sites_in_prefix],
        "sections": sections,
    }


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument("--manifest", type=Path,
                        default=Path("docs/mappings/resident-fragments.json"))
    parser.add_argument("--output-dir", type=Path, default=Path("docs/sections"))
    parser.add_argument("--inspect", type=int)
    args = parser.parse_args()
    rom = args.rom.read_bytes()
    if hashlib.sha256(rom).hexdigest() != EXPECTED_SHA256:
        raise ValueError("wrong input ROM")
    manifest = json.loads(args.manifest.read_text())
    reports = []
    for index, metadata in enumerate(manifest["fragments"]):
        image = load_image(rom, metadata)
        report = map_image(image, metadata)
        report["image_index"] = index
        reports.append(report)
        if args.inspect == index:
            print(json.dumps(report, indent=2))
            for offset in range(0x20, min(word(image, 0x14), 0x100), 4):
                print(f"{offset:06X} {base_address(metadata)+offset:08X} "
                      f"{word(image,offset):08X} "
                      f"{rabbitizer.Instruction(word(image,offset),base_address(metadata)+offset).disassemble()}")
            return
    summary = {
        "image_count": len(reports),
        "instruction_bytes": sum(report["instruction_bytes"] for report in reports),
        "images_with_rejected_paths": sum(bool(report["rejected"]) for report in reports),
        "images_with_indirect_jumps": sum(bool(report["unresolved_indirect_jumps"]) for report in reports),
        "images_with_cpu_code_evidence": sum(report["classification"] == "cpu_code_present"
                                            for report in reports),
        "images_without_cpu_code_evidence": sum(report["classification"] == "no_cpu_code_evidence"
                                               for report in reports),
        "candidate_text_envelope_bytes": sum(int(report["text_envelope"][1], 0) - 0x20
                                             for report in reports if report["text_envelope"]),
    }
    args.output_dir.mkdir(parents=True, exist_ok=True)
    (args.output_dir / "fragment-sections.json").write_text(
        json.dumps({"summary": summary, "images": reports}, indent=2) + "\n")
    with (args.output_dir / "fragment-sections.csv").open("w", newline="") as output:
        writer = csv.writer(output)
        writer.writerow(["image_index", "rom_start", "storage", "link_base", "classification",
                         "text_start", "text_end_exclusive", "instruction_evidence_bytes",
                         "unresolved_indirect_jumps", "rejected_paths"])
        for report in reports:
            writer.writerow([report["image_index"], report["rom_start"], report["storage"],
                             report["link_base"], report["classification"],
                             *(report["text_envelope"] or ["", ""]),
                             report["instruction_bytes"], len(report["unresolved_indirect_jumps"]),
                             len(report["rejected"])])
    print(json.dumps(summary, indent=2))


def base_address(metadata):
    return int(metadata["link_base"], 0)


if __name__ == "__main__":
    main()
