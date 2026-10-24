#!/usr/bin/env python3
"""Find the ROM addresses of src/ files' own .rodata/.data/.bss sections.

Each file is compiled the way `make rom` compiles it. Every relocation from
its .text into one of its data sections is solved against the retail
instruction words at the file's address, which gives that section's link
address. All references to a section must agree. Results are written to
config/jp/sections.json; `make rom` then places the sections there and the
image comparison checks their bytes.

--unwrap first replaces the NON_MATCHING-held C of each file (functions kept
as GLOBAL_ASM only because their data was not placed) with the C itself.

Usage: tools/place_sections.py [--unwrap] src/file.c ...
"""
import argparse
import csv
import io
import json
from pathlib import Path
import re
import struct
import tempfile

from elftools.elf.elffile import ELFFile

import production
from map_fragment_sections import load_image

ROOT = production.ROOT
HELD = re.compile(r'#ifdef NON_MATCHING\n// Matches the ROM, but uses [^\n]*\n(.*?)#else\n'
                  r'#pragma GLOBAL_ASM\("[^"]*/(\w+)\.s"\)\n#endif\n', re.S)
DATA = ('.rodata', '.data', '.bss')


def sext16(value):
    return value - 0x10000 if value & 0x8000 else value


def unwrap(path):
    """Replace held blocks with their C; return the owner names that became C."""
    text = (ROOT / path).read_text(encoding='utf-8')
    names = [m[2] for m in HELD.finditer(text)]
    (ROOT / path).write_text(HELD.sub(lambda m: m[1], text), encoding='utf-8')
    return names


def file_placement(path, rows, owners, images, rom, mapping):
    """(image index, start link address) of a file's first owner."""
    starts = [owners[r['owner']] for r in rows if r['source'] == path]
    index = starts[0]['image_index']
    first = min(starts, key=lambda o: int(o['start'], 0))
    if index not in images:
        images[index] = rom[:0x80C00] if index is None else load_image(rom, mapping['fragments'][index])
    base = 0x7FFFF400 if index is None else int(mapping['fragments'][index]['link_base'], 0)
    return index, int(first['start'], 0), base


def solve(obj, image, start, base):
    elf = ELFFile(io.BytesIO(obj.read_bytes()))
    sections = list(elf.iter_sections())
    text = elf.get_section_by_name('.text')
    rel = elf.get_section_by_name('.rel.text')
    symtab = elf.get_section_by_name('.symtab')
    if rel is None:
        return {}
    words = text.data()
    entries = sorted(rel.iter_relocations(), key=lambda e: e['r_offset'])
    targets = {}
    pending = {}
    for entry in entries:
        sym = symtab.get_symbol(entry['r_info_sym'])
        if sym['st_info']['type'] != 'STT_SECTION':
            continue
        section = sections[sym['st_shndx']].name
        if section not in DATA:
            continue
        offset = entry['r_offset']
        got = struct.unpack_from('>I', words, offset)[0]
        want = struct.unpack_from('>I', image, start + offset)[0]
        kind = entry['r_info_type']
        if kind == 5:  # HI16: remember by destination register
            pending[(section, (got >> 16) & 31)] = (got, want)
        elif kind == 6:  # LO16 paired with the HI16 that loaded its base register
            hi = pending.get((section, (got >> 21) & 31))
            if hi is None:
                raise ValueError(f'{obj.name}: unpaired %lo at 0x{offset:X}')
            addend = ((hi[0] & 0xFFFF) << 16) + sext16(got & 0xFFFF)
            target = ((hi[1] & 0xFFFF) << 16) + sext16(want & 0xFFFF)
            targets.setdefault(section, set()).add((target - addend) & 0xFFFFFFFF)
        elif kind == 2:  # R_MIPS_32 in .text (rare)
            targets.setdefault(section, set()).add((want - got) & 0xFFFFFFFF)
    result = {}
    for section, bases in targets.items():
        if len(bases) != 1:
            raise ValueError(f'{obj.name}: {section} references disagree: '
                             + ', '.join(f'0x{b:08X}' for b in sorted(bases)))
        address = bases.pop()
        result[section] = f'0x{address:08X}'
        contents = elf.get_section_by_name(section)
        if contents['sh_type'] == 'SHT_NOBITS':
            continue
        # IDO pads the section to 16 bytes. When the next object's data starts
        # inside that zero padding, record the shorter size actually present.
        data = contents.data()
        used = len(data.rstrip(b'\0'))
        used += -used % 4
        offset = address - base
        tail = image[offset + used:offset + len(data)]
        if any(tail):
            size = used + next(i for i, b in enumerate(tail) if b) // 4 * 4
            result[section] = {'address': f'0x{address:08X}', 'size': f'0x{size:X}'}
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    parser.add_argument('sources', nargs='+')
    parser.add_argument('--unwrap', action='store_true')
    args = parser.parse_args()
    rom = (ROOT / 'baseroms/jp/baserom.z64').read_bytes()
    mapping = json.loads((ROOT / 'docs/mappings/resident-fragments.json').read_text())
    inventory = json.loads((ROOT / 'docs/pragma-inventory.json').read_text())
    owners = {row['name']: row for row in inventory['owners']}
    matches = ROOT / 'docs/function-matches.csv'
    with matches.open() as handle:
        rows = list(csv.DictReader(handle))
    registry = json.loads(production.SECTION_REGISTRY.read_text())
    compilers = {'5.3': str(ROOT / 'tools/ido5.3/cc'), '7.1': str(ROOT / 'tools/ido7.1/cc')}
    images = {}
    became_c = set()
    for path in args.sources:
        if args.unwrap:
            became_c.update(unwrap(path))
        index, start, base = file_placement(path, rows, owners, images, rom, mapping)
        with tempfile.TemporaryDirectory() as temporary:
            obj = production.compile_source_file(path, Path(temporary), compilers, 'mips-linux-gnu-')
            placed = solve(obj, images[index], start, base)
        if placed:
            registry[path] = placed
        else:
            registry.pop(path, None)
        print(path, placed)
    if became_c:
        for row in rows:
            if row['owner'] in became_c:
                row['build'] = 'c'
        with matches.open('w', newline='') as handle:
            writer = csv.DictWriter(handle, fieldnames=rows[0].keys(), lineterminator='\n')
            writer.writeheader()
            writer.writerows(rows)
    production.SECTION_REGISTRY.write_text(json.dumps(dict(sorted(registry.items())), indent=2) + '\n')


if __name__ == '__main__':
    main()
