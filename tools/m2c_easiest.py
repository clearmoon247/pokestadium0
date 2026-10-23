#!/usr/bin/env python3
"""Generate a bounded batch of smallest owners with m2c; check unmodified C bytes.

Compiler checks are function-only evidence, never production ROM acceptance.
Run extraction first. No C variants, hand corrections, or other decompilers.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
FLAGS = ['-c', '-O2', '-mips2', '-G', '0', '-non_shared',
         '-Xcpluscomm', '-nostdinc', '-Wab,-r4300_mul']
TYPES = ('typedef signed char s8;\ntypedef signed short s16;\n'
         'typedef signed int s32;\ntypedef signed long long s64;\n'
         'typedef unsigned char u8;\ntypedef unsigned short u16;\n'
         'typedef unsigned int u32;\ntypedef unsigned long long u64;\n'
         'typedef float f32;\ntypedef double f64;\n'
         '#include "tools/m2c/m2c_macros.h"\n')


def sha(data):
    return hashlib.sha256(data).hexdigest()


def run(argv):
    result = subprocess.run(argv, cwd=ROOT, capture_output=True)
    if result.returncode:
        raise RuntimeError(result.stderr.decode() + result.stdout.decode())
    return result.stdout


def function_bytes(path, name):
    """Read a defined function and reject any relocation in its byte range."""
    data = path.read_bytes()
    if data[:6] != b'\x7fELF\x01\x02':
        raise ValueError('expected ELF32 big-endian object')
    header = struct.unpack_from('>16sHHIIIIIHHHHHH', data)
    sections = [struct.unpack_from('>IIIIIIIIII', data, header[6] + i * header[11])
                for i in range(header[12])]
    for section in sections:
        if section[1] != 2:
            continue
        strings = sections[section[6]]
        names = data[strings[4]:strings[4] + strings[5]]
        for offset in range(section[4], section[4] + section[5], section[9]):
            index, value, size, info, other, owner = struct.unpack_from('>IIIBBH', data, offset)
            symbol = names[index:].split(b'\0', 1)[0].decode()
            if symbol != name or info & 15 != 2 or owner == 0:
                continue
            if not size:
                raise ValueError('function symbol has no size')
            start = value - sections[owner][3]
            for reloc in sections:
                if reloc[1] in (4, 9) and reloc[7] == owner:
                    for pos in range(reloc[4], reloc[4] + reloc[5], reloc[9]):
                        address = struct.unpack_from('>I', data, pos)[0]
                        if start <= address < start + size:
                            raise ValueError('function has unresolved relocation')
            offset = sections[owner][4] + start
            return data[offset:offset + size]
    raise ValueError('function symbol not found: ' + name)


def link_function(obj, row, prefix):
    undefined = run([prefix + 'nm', '-u', str(obj)]).decode().splitlines()
    script = ['SECTIONS {', f'.text {row["link_start"]} : {{ *(.text) }}',
              '/DISCARD/ : { *(*) }', '}']
    for line in undefined:
        if not line.strip():
            continue
        symbol = line.split()[-1]
        match = re.fullmatch(r'(?:func_|D_(?:(?:FLT|DBL|STR)_)?|jtbl_|\.L)([0-9A-F]{8})(?:_\d+)?', symbol)
        if not match:
            raise ValueError('unknown symbol address: ' + symbol)
        script.append(f'PROVIDE({symbol} = 0x{match[1]});')
    script_path = obj.with_suffix('.ld')
    script_path.write_text('\n'.join(script) + '\n')
    linked = obj.with_suffix('.elf')
    command = [prefix + 'ld', '-T', str(script_path.relative_to(ROOT)), '-o', str(linked.relative_to(ROOT)), str(obj.relative_to(ROOT))]
    run(command)
    return function_bytes(linked, row['name']), command, script_path.read_text()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cc', type=Path, required=True, help='stock IDO 5.3 cc')
    parser.add_argument('--start', type=int, default=0)
    parser.add_argument('--count', type=int, default=100)
    parser.add_argument('--link', action='store_true', help='resolve symbolic relocations before comparing')
    parser.add_argument('--prefix', default='mips-linux-gnu-')
    args = parser.parse_args()
    cc = args.cc.resolve()
    inventory = json.loads((ROOT / 'docs/pragma-inventory.json').read_text())
    def difficulty(row):
        listing = (ROOT / row['assembly']).read_text()
        words = re.findall(r'/\*\s+[0-9A-F]+\s+[0-9A-F]+\s+([0-9A-F]{8})\s*\*/', listing)
        empty = words == ['03E00008', '00000000']
        return row['size'], not empty, row['assembly']

    if args.start < 0 or args.count < 1:
        parser.error('start must be nonnegative and count positive')
    rows = sorted(inventory['owners'], key=difficulty)[args.start:args.start + args.count]
    if len(rows) != args.count:
        parser.error('batch extends beyond inventory')
    batch = 'm2c-easiest' if args.start == 0 else f'm2c-batch-{args.start + 1}-{args.start + args.count}'
    scratch = ROOT / '.analysis' / batch
    scratch.mkdir(parents=True, exist_ok=True)
    candidates = ROOT / 'candidates' / batch
    candidates.mkdir(parents=True, exist_ok=True)
    results = []
    for row in rows:
        assembly = ROOT / row['assembly']
        if sha(assembly.read_bytes()) != row['assembly_sha256']:
            raise ValueError('stale assembly: ' + str(assembly))
        target = b''.join(bytes.fromhex(word) for word in re.findall(
            r'/\*\s+[0-9A-F]+\s+[0-9A-F]+\s+([0-9A-F]{8})\s*\*/', assembly.read_text()))
        if len(target) != row['size'] or sha(target) != row['input_sha256']:
            raise ValueError('listing differs from ROM inventory')
        command = [sys.executable, 'tools/m2c/m2c.py', '-t', 'mips-ido-c', '--valid-syntax', row['assembly']]
        candidate = run(command)
        candidate_path = candidates / (row['name'] + '.c')
        candidate_path.write_bytes(candidate)
        # Primitive typedefs supply widths only; m2c output remains byte-for-byte intact.
        unit = scratch / (row['name'] + '.compile.c')
        unit.write_bytes(TYPES.encode() + candidate)
        obj = unit.with_suffix('.o')
        compile_command = [str(cc), *FLAGS, '-I.', str(unit.relative_to(ROOT)), '-o', str(obj.relative_to(ROOT))]
        result = dict(name=row['name'], source=row['source'], assembly=row['assembly'],
                            size=row['size'], candidate=str(candidate_path.relative_to(ROOT)), candidate_sha256=sha(candidate),
                            assembly_sha256=row['assembly_sha256'], target_sha256=sha(target),
                            instruction_words_identical=False,
                            m2c_command=command[1:], compile_command=compile_command[1:])
        try:
            run(compile_command)
        except RuntimeError as error:
            result.update(status='compile_error', diagnostic=str(error))
        else:
            try:
                actual = function_bytes(obj, row['name'])
            except ValueError as error:
                result.update(status='object_check_error', diagnostic=str(error))
                if args.link and str(error) == 'function has unresolved relocation':
                    try:
                        actual, link_command, link_script = link_function(obj, row, args.prefix)
                    except (ValueError, RuntimeError) as link_error:
                        result.update(status='link_error', diagnostic=str(link_error))
                    else:
                        exact = actual == target
                        result.update(compiled_sha256=sha(actual), compiled_size=len(actual),
                                      instruction_words_identical=exact,
                                      status='exact' if exact else 'byte_mismatch',
                                      comparison_layer='linked_function', link_command=link_command,
                                      link_script=link_script)
                        result.pop('diagnostic', None)
            else:
                exact = actual == target
                result.update(compiled_sha256=sha(actual), compiled_size=len(actual),
                              instruction_words_identical=exact,
                              status='exact' if exact else 'byte_mismatch')
        results.append(result)
        if len(results) % 25 == 0:
            print(f'{len(results)}/{len(rows)} checked; {sum(r["instruction_words_identical"] for r in results)} exact', flush=True)
    report = dict(input_sha256=inventory['input_sha256'],
                  m2c_commit=run(['git', '-C', 'tools/m2c', 'rev-parse', 'HEAD']).decode().strip(),
                  compiler_sha256=sha(cc.read_bytes()), compiler_flags=FLAGS,
                  compiler_directory_sha256={p.name: sha(p.read_bytes())
                                             for p in sorted(cc.parent.iterdir()) if p.is_file()},
                  compile_prefix=TYPES,
                  m2c_macros_sha256=sha((ROOT / 'tools/m2c/m2c_macros.h').read_bytes()),
                  selection=f'ranks {args.start + 1}-{args.start + args.count} sorted by (size, empty-return first, assembly path); no C edits',
                  generated=len(results), instruction_words_identical=sum(r['instruction_words_identical'] for r in results),
                  full_rom_gate='NOT RUN: production ROM build not implemented', results=results)
    report_name = 'm2c-easiest-100' if args.start == 0 and args.count == 100 else batch
    (ROOT / f'docs/pragma-evidence/{report_name}.json').write_text(json.dumps(report, indent=2) + '\n')
    print(f'{len(results)} m2c candidates; {report["instruction_words_identical"]} function-byte matches; full ROM gate NOT RUN')


if __name__ == '__main__':
    main()
