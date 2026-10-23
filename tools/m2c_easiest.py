#!/usr/bin/env python3
"""Generate exactly 100 smallest owners with m2c; check unmodified C bytes.

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


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cc', type=Path, required=True, help='stock IDO 5.3 cc')
    args = parser.parse_args()
    cc = args.cc.resolve()
    inventory = json.loads((ROOT / 'docs/pragma-inventory.json').read_text())
    def difficulty(row):
        listing = (ROOT / row['assembly']).read_text()
        words = re.findall(r'/\*\s+[0-9A-F]+\s+[0-9A-F]+\s+([0-9A-F]{8})\s*\*/', listing)
        empty = words == ['03E00008', '00000000']
        return row['size'], not empty, row['assembly']

    rows = sorted(inventory['owners'], key=difficulty)[:100]
    scratch = ROOT / '.analysis/m2c-easiest'
    scratch.mkdir(parents=True, exist_ok=True)
    candidates = ROOT / 'candidates/m2c-easiest'
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
        run(compile_command)
        actual = function_bytes(obj, row['name'])
        exact = actual == target
        results.append(dict(name=row['name'], source=row['source'], assembly=row['assembly'],
                            size=row['size'], candidate=str(candidate_path.relative_to(ROOT)), candidate_sha256=sha(candidate),
                            assembly_sha256=row['assembly_sha256'], target_sha256=sha(target),
                            compiled_sha256=sha(actual), instruction_words_identical=exact,
                            m2c_command=command[1:], compile_command=compile_command[1:]))
        if not exact:
            raise ValueError('function bytes differ: ' + row['name'])
    report = dict(input_sha256=inventory['input_sha256'],
                  m2c_commit=run(['git', '-C', 'tools/m2c', 'rev-parse', 'HEAD']).decode().strip(),
                  compiler_sha256=sha(cc.read_bytes()), compiler_flags=FLAGS,
                  compiler_directory_sha256={p.name: sha(p.read_bytes())
                                             for p in sorted(cc.parent.iterdir()) if p.is_file()},
                  compile_prefix=TYPES,
                  m2c_macros_sha256=sha((ROOT / 'tools/m2c/m2c_macros.h').read_bytes()),
                  selection='first 100 sorted by (size, empty-return first, assembly path); no C edits',
                  generated=100, instruction_words_identical=sum(r['instruction_words_identical'] for r in results),
                  full_rom_gate='NOT RUN: production ROM build not implemented', results=results)
    (ROOT / 'docs/pragma-evidence/m2c-easiest-100.json').write_text(json.dumps(report, indent=2) + '\n')
    print('100 m2c candidates; 100 function-byte matches; full ROM gate NOT RUN')


if __name__ == '__main__':
    main()
