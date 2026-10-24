#!/usr/bin/env python3
"""Fixed-layout C/assembly ROM build, with separately retained opaque assets.

No original owner bytes survive in the extracted image assets. Every owner
comes from a compiler or assembler object placed by the image linker script.
"""
import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess

from map_fragment_sections import load_image
from map_rom import EXPECTED_SHA256, trace_yay0
from m2c_easiest import FLAGS, TYPES

ROOT = Path(__file__).resolve().parents[1]
ASSETS = ROOT / 'assets/production'
BUILD = ROOT / 'build/production'
LISTING = re.compile(r'/\*\s+[0-9A-F]+\s+([0-9A-F]+)\s+([0-9A-F]{8})\s*\*/\s*(.*)')
MACROS = '''.set noreorder
.set noat
.set gp=64
.macro nonmatching name, size
.endm
.macro glabel name
.globl \\name
.type \\name, @function
\\name:
.endm
.macro alabel name
.globl \\name
\\name:
.endm
.macro endlabel name
.size \\name, . - \\name
.endm
'''


def sha(data):
    return hashlib.sha256(data).hexdigest()


def run(argv):
    result = subprocess.run([str(x) for x in argv], cwd=ROOT, capture_output=True)
    if result.returncode:
        raise RuntimeError(' '.join(map(str, argv)) + '\n' + result.stderr.decode() + result.stdout.decode())
    return result.stdout


def tokens(packed):
    """Yield literal positions and backreferences in a validated Yay0 stream."""
    size, links, literals = struct.unpack_from('>3I', packed, 4)
    mask_cursor, mask, remaining, output = 16, 0, 0, 0
    while output < size:
        if not remaining:
            mask = struct.unpack_from('>I', packed, mask_cursor)[0]
            mask_cursor += 4
            remaining = 32
        if mask & 0x80000000:
            yield output, literals, 1, 0
            literals += 1
            output += 1
        else:
            value = struct.unpack_from('>H', packed, links)[0]
            links += 2
            length = value >> 12
            distance = (value & 4095) + 1
            if not length:
                length = packed[literals] + 18
                literals += 1
            else:
                length += 2
            yield output, None, length, distance
            output += length
        remaining -= 1
        mask = (mask << 1) & 0xFFFFFFFF


def storage_template(stored):
    """Retain compression topology, erase every encoded image literal/override."""
    offset, size, _, count = struct.unpack_from('>4I', stored, 8)
    decoded, _ = trace_yay0(stored[offset:])
    if len(decoded) != size:
        raise ValueError('wrapper decoded length differs')
    template = bytearray(stored)
    placeholders = []
    for index in range(count):
        position = struct.unpack_from('>I', stored, 28 + index * 8)[0]
        placeholders.append([position, decoded[position:position + 4].hex()])
        template[24 + index * 8:28 + index * 8] = bytes(4)
    for _, literal, _, _ in tokens(stored[offset:]):
        if literal is not None:
            template[offset + literal] = 0
    return bytes(template), placeholders


def encode_image(image, template, placeholders):
    """Re-emit literals from rebuilt bytes using the original compression plan.

    A changed backreference must fail, rather than silently retaining old code.
    This preserves retail storage identity without guessing a compressor lineage.
    """
    result = bytearray(template)
    offset, size, _, count = struct.unpack_from('>4I', result, 8)
    if len(image) != size:
        raise ValueError('fixed-layout decoded image changed size')
    decoded = bytearray(image)
    if len(placeholders) != count:
        raise ValueError('restoration count differs')
    for index, (position, original) in enumerate(placeholders):
        if struct.unpack_from('>I', result, 28 + index * 8)[0] != position:
            raise ValueError('restoration position differs')
        result[24 + index * 8:28 + index * 8] = decoded[position:position + 4]
        decoded[position:position + 4] = bytes.fromhex(original)
    for output, literal, length, distance in tokens(template[offset:]):
        if literal is not None:
            result[offset + literal] = decoded[output]
        else:
            if distance > output or output + length > len(decoded):
                raise ValueError('invalid retained compression plan')
            for index in range(length):
                if decoded[output + index] != decoded[output + index - distance]:
                    raise ValueError('changed image cannot use retained Yay0 backreference')
    restored, _ = trace_yay0(result[offset:])
    restored = bytearray(restored)
    for index, (position, _) in enumerate(placeholders):
        restored[position:position + 4] = result[24 + index * 8:28 + index * 8]
    if restored != image:
        raise ValueError('encoded image does not restore to linked image')
    return bytes(result)


def extract():
    rom = (ROOT / 'baseroms/jp/baserom.z64').read_bytes()
    if sha(rom) != EXPECTED_SHA256:
        raise ValueError('wrong input ROM')
    mapping = json.loads((ROOT / 'docs/mappings/resident-fragments.json').read_text())
    inventory = json.loads((ROOT / 'docs/pragma-inventory.json').read_text())
    ASSETS.mkdir(parents=True, exist_ok=True)
    groups = []
    specifications = [('resident', None, 0, 0x80C00, 0x7FFFF400, rom[:0x80C00], None)]
    for index, meta in enumerate(mapping['fragments']):
        specifications.append((f'fragment{index:03}', index, int(meta['rom_start'], 0),
                               int(meta['rom_consumed_end'], 0), int(meta['link_base'], 0),
                               load_image(rom, meta), meta))
    for name, index, start, end, base, image, meta in specifications:
        owners = [r for r in inventory['owners'] if r['image_index'] == index]
        image_assets = bytearray(image)
        cursor = 0
        for row in sorted(owners, key=lambda r: int(r['start'], 0)):
            begin, stop = int(row['start'], 0), int(row['end'], 0)
            if begin < cursor or sha(image[begin:stop]) != row['input_sha256']:
                raise ValueError('owner overlap or input mismatch')
            image_assets[begin:stop] = bytes(stop - begin)
            cursor = stop
        (ASSETS / f'{name}.bin').write_bytes(image_assets)
        group = dict(name=name, image_index=index, rom_start=start, rom_end=end,
                     base=base, size=len(image), expected_sha256=sha(image),
                     asset_sha256=sha(image_assets), owners=owners,
                     storage='raw' if meta is None else meta['storage'])
        if group['storage'] != 'raw':
            template, placeholders = storage_template(rom[start:end])
            (ASSETS / f'{name}.storage').write_bytes(template)
            group.update(placeholders=placeholders, template_sha256=sha(template))
        groups.append(group)
    gaps = []
    cursor = 0
    for group in groups:
        if group['rom_start'] > cursor:
            name = f'opaque_{cursor:X}.bin'
            data = rom[cursor:group['rom_start']]
            (ASSETS / name).write_bytes(data)
            gaps.append(dict(start=cursor, end=group['rom_start'], asset=name, sha256=sha(data)))
        if group['rom_start'] < cursor:
            raise ValueError('ROM storage overlap')
        cursor = group['rom_end']
    if cursor < len(rom):
        name = f'opaque_{cursor:X}.bin'
        data = rom[cursor:]
        (ASSETS / name).write_bytes(data)
        gaps.append(dict(start=cursor, end=len(rom), asset=name, sha256=sha(data)))
    manifest = dict(input_sha256=EXPECTED_SHA256, size=len(rom), groups=groups, gaps=gaps)
    (ASSETS / 'manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
    print(f'Extracted {len(groups)} images; erased {len(inventory["owners"])} code-owner ranges from opaque assets', flush=True)


def canonical_assembly(text):
    """Disambiguate assembler aliases; never substitute raw instruction words."""
    lines = []
    controls = dict(Index=0, Random=1, EntryLo0=2, EntryLo1=3, Context=4,
                    PageMask=5, Wired=6, BadVaddr=8, Count=9, EntryHi=10,
                    Compare=11, Status=12, Cause=13, EPC=14, PRId=15,
                    Config=16, LLAddr=17, WatchLo=18, WatchHi=19,
                    XContext=20, ParityError=26, CacheErr=27, TagLo=28,
                    TagHi=29, ErrorEPC=30, FpcCsr=31, FpcIrr=0)
    for line in text.splitlines():
        match = LISTING.search(line)
        if match:
            value = int(match[2], 16)
            mnemonic = match[3].split()[0]
            instruction = match[3].split('/*', 1)[0].strip()
            operands = instruction.split(None, 1)
            operands = [part.strip() for part in operands[1].split(',')] if len(operands) > 1 else []
            replacement = None
            if mnemonic == 'move':
                if value & 63 not in (33, 37) or len(operands) != 2:
                    raise ValueError('unsupported move alias')
                opcode = 'or' if value & 63 == 37 else 'addu'
                dest, source = operands
                sources = f'$zero, {source}' if (value >> 21) & 31 == 0 else f'{source}, $zero'
                replacement = f'{opcode} {dest}, {sources}'
            elif mnemonic in ('div', 'divu') and value >> 26 == 0 and len(operands) == 2:
                replacement = f'{mnemonic} $0, {operands[0]}, {operands[1]}'
            elif mnemonic in ('cfc1', 'ctc1', 'mfc0', 'mtc0', 'dmfc0', 'dmtc0'):
                if len(operands) == 2 and operands[1].lstrip('$') in controls:
                    replacement = f'{mnemonic} {operands[0]}, ${controls[operands[1].lstrip("$")]}'
            if replacement:
                line = line[:match.start(3)] + replacement
            if mnemonic in ('dmfc1', 'dmtc1'):
                lines.extend(['.set fp=64', line, '.set fp=32'])
                continue
        lines.append(line)
    return '\n'.join(lines) + '\n'


def trim_text(obj, name, size):
    """Remove assembler alignment padding after a lone C function, keeping relocations."""
    data = bytearray(obj.read_bytes())
    if data[:6] != b'\x7fELF\x01\x02':
        raise ValueError('expected big-endian ELF32')
    header = struct.unpack_from('>16sHHIIIIIHHHHHH', data)
    positions = [header[6] + i * header[11] for i in range(header[12])]
    sections = [struct.unpack_from('>IIIIIIIIII', data, p) for p in positions]
    table = sections[header[13]]
    strings = data[table[4]:table[4] + table[5]]
    found = False
    for section in sections:
        if section[1] != 2:
            continue
        names_section = sections[section[6]]
        names = data[names_section[4]:names_section[4] + names_section[5]]
        for offset in range(section[4], section[4] + section[5], section[9]):
            index, value, symbol_size, info, _, _ = struct.unpack_from('>IIIBBH', data, offset)
            if names[index:].split(b'\0', 1)[0].decode() == name and info & 15 == 2:
                if value != 0 or symbol_size != size:
                    raise ValueError('C function symbol size differs: ' + name)
                found = True
    if not found:
        raise ValueError('C function symbol missing: ' + name)
    for position, section in zip(positions, sections):
        section_name = strings[section[0]:].split(b'\0', 1)[0]
        if section_name == b'.text':
            if section[5] < size or any(data[section[4] + size:section[4] + section[5]]):
                raise ValueError('C function is oversized or has nonzero trailing content: ' + name)
            struct.pack_into('>I', data, position + 20, size)
            struct.pack_into('>I', data, position + 32, 4)
            obj.write_bytes(data)
            return
    raise ValueError('no C text section')


def build_group(group, selected, cc, prefix, compare):
    name = group['name']
    directory = BUILD / name
    directory.mkdir(parents=True, exist_ok=True)
    assembly = [MACROS]
    sections = []
    c_objects = []
    counts = Counter()
    cursor = 0
    def gap(begin, end):
        if end > begin:
            section = f'.gap_{begin:X}'
            assembly.append(f'.section {section}, "a", @progbits\n.incbin "assets/production/{name}.bin", {begin}, {end - begin}\n')
            sections.append((begin, end - begin, 'assembly.o', section))
    for row in sorted(group['owners'], key=lambda r: int(r['start'], 0)):
        begin, end = int(row['start'], 0), int(row['end'], 0)
        gap(cursor, begin)
        if row['name'] in selected:
            candidate = ROOT / selected[row['name']]['candidate']
            unit = directory / (row['name'] + '.c')
            unit.write_bytes(TYPES.encode() + candidate.read_bytes())
            obj = directory / (row['name'] + '.o')
            run([cc, *FLAGS, '-I.', unit, '-o', obj])
            trim_text(obj, row['name'], row['size'])
            c_objects.append(obj)
            sections.append((begin, end - begin, obj.name, '.text'))
            counts['c'] += 1
        else:
            section = '.text_' + row['name']
            assembly.append(f'.section {section}, "ax", @progbits\n')
            listing = ROOT / row['assembly']
            assembly.append(canonical_assembly(listing.read_text()))
            sections.append((begin, end - begin, 'assembly.o', section))
            counts['asm'] += 1
        cursor = end
    gap(cursor, group['size'])
    source = directory / 'assembly.s'
    source.write_text('\n'.join(assembly))
    assembly_obj = directory / 'assembly.o'
    run([prefix + 'as', '-march=vr4300', '-32', '-G0', source, '-o', assembly_obj])
    objects = [assembly_obj, *c_objects]
    undefined = set()
    for line in run([prefix + 'nm', '-u', *objects]).decode().splitlines():
        if re.match(r'\s*U\s+', line):
            undefined.add(line.split()[-1])
    linker = ['PHDRS { prefix PT_LOAD FLAGS(4); body PT_LOAD FLAGS(7); }', 'SECTIONS {']
    for index, (begin, size, obj, section) in enumerate(sections):
        output = f'.part_{index}'
        segment = 'prefix' if index == 0 else 'body'
        linker.append(f'{output} 0x{group["base"] + begin:X} : AT({begin}) SUBALIGN(4) {{ "{directory / obj}"({section}) }} :{segment}')
        linker.append(f'ASSERT(SIZEOF({output}) == {size}, "size differs: {name} {section}")')
    linker.append('/DISCARD/ : { *(*) }\n}')
    for symbol in sorted(undefined):
        match = re.fullmatch(r'(?:func_|D_(?:(?:FLT|DBL|STR)_)?|jtbl_|\.L)([0-9A-F]{8})(?:_\d+)?', symbol)
        if not match:
            raise ValueError('unresolved symbol has no established address: ' + symbol)
        linker.append(f'PROVIDE({symbol} = 0x{match[1]});')
    script = directory / 'link.ld'
    script.write_text('\n'.join(linker) + '\n')
    elf = directory / (name + '.elf')
    run([prefix + 'ld', '-T', script, '-Map', directory / 'link.map', '-o', elf, *objects])
    output = directory / (name + '.bin')
    run([prefix + 'objcopy', '-O', 'binary', elf, output])
    image = output.read_bytes()
    if len(image) != group['size']:
        raise ValueError('linked image size differs: ' + name)
    if compare and sha(image) != group['expected_sha256']:
        raise ValueError('linked image bytes differ: ' + name)
    if group['storage'] != 'raw':
        image = encode_image(image, (ASSETS / f'{name}.storage').read_bytes(), group['placeholders'])
    return group, image, counts


def build(cc, prefix, compare, jobs, asm_only):
    manifest = json.loads((ASSETS / 'manifest.json').read_text())
    BUILD.mkdir(parents=True, exist_ok=True)
    receipt_path = BUILD / 'receipt.json'
    receipt_path.write_text(json.dumps(dict(status='incomplete', full_rom_identical=False)) + '\n')
    selected = {}
    if not asm_only:
        rows = json.loads((ROOT / 'config/jp/matching.json').read_text())
        for row in rows:
            if row['name'] in selected:
                raise ValueError('duplicate C owner: ' + row['name'])
            selected[row['name']] = row
        known = {row['name'] for group in manifest['groups'] for row in group['owners']}
        if selected.keys() - known:
            raise ValueError('matching registry contains unknown owners')
    output = bytearray(manifest['size'])
    for gap in manifest['gaps']:
        data = (ASSETS / gap['asset']).read_bytes()
        if sha(data) != gap['sha256']:
            raise ValueError('opaque asset changed: ' + gap['asset'])
        output[gap['start']:gap['end']] = data
    counts = Counter()
    def task(group):
        return build_group(group, selected, cc, prefix, compare)
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        for index, (group, image, totals) in enumerate(pool.map(task, manifest['groups']), 1):
            if len(image) != group['rom_end'] - group['rom_start']:
                raise ValueError('stored image changed size')
            output[group['rom_start']:group['rom_end']] = image
            counts.update(totals)
            if index % 25 == 0:
                print(f'{index}/{len(manifest["groups"])} images linked', flush=True)
    exact = sha(output) == EXPECTED_SHA256
    if compare and not exact:
        raise ValueError('full ROM differs')
    target = ROOT / 'build/pokestadium0-jp.z64'
    target.write_bytes(output)
    receipt = dict(status='PASS' if exact and compare else 'BUILT',
                   input_sha256=manifest['input_sha256'], output_sha256=sha(output),
                   full_rom_identical=exact, compare=compare, c_owners=counts['c'],
                   asm_owners=counts['asm'], linked_images=len(manifest['groups']),
                   compiler_sha256=sha(Path(cc).read_bytes()) if counts['c'] else None,
                   matching_registry_sha256=sha((ROOT / 'config/jp/matching.json').read_bytes()),
                   build_tools_sha256={name: sha((ROOT / name).read_bytes()) for name in
                                       ('tools/production.py', 'tools/m2c_easiest.py')},
                   binutils={tool: run([prefix + tool, '--version']).decode().splitlines()[0]
                             for tool in ('as', 'ld', 'objcopy')},
                   c_sources_sha256={row['candidate']: sha((ROOT / row['candidate']).read_bytes())
                                     for row in selected.values()})
    receipt_path.write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps({key: value for key, value in receipt.items() if key != 'c_sources_sha256'}, indent=2), flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', choices=['extract', 'build'])
    parser.add_argument('--cc', default='tools/ido5.3/cc')
    parser.add_argument('--prefix', default='mips-linux-gnu-')
    parser.add_argument('--compare', type=int, choices=[0, 1], default=1)
    parser.add_argument('--jobs', type=int, default=4)
    parser.add_argument('--asm-only', action='store_true')
    args = parser.parse_args()
    if args.command == 'extract':
        extract()
    else:
        build(str(Path(args.cc).resolve()), args.prefix, bool(args.compare), args.jobs, args.asm_only)


if __name__ == '__main__':
    main()
