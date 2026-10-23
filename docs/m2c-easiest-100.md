# First 100 m2c function-byte matches

The 100 candidates in `candidates/m2c-easiest/` reproduce their individual
eight-byte assembly owners exactly with the existing GS checkout's IDO 5.3
compiler and `-O2 -mips2 -G 0 -non_shared -Xcpluscomm -nostdinc
-Wab,-r4300_mul`. All 100 are empty returns. These are deliberately the easiest
functions, not 100 substantial game routines.

**Full-ROM acceptance: NOT RUN.** Stadium Zero's production build and linker
remain unimplemented. This experiment does not confirm the original compiler,
function boundaries, translation units, or a rebuilt ROM. The default source
continues to use assembly; these candidates have not been promoted to matching
production C or counted in `COVERAGE.md`.

Only m2c produced the C. Its output was saved verbatim, with no hand corrections,
context hints, source variants, or permuter. Extraction used this repository's
pinned tools. IDO was used only to verify the generated candidates, as in the
GS workflow. Primitive type definitions and m2c's own macro header are added
to temporary compilation wrappers, outside the saved candidate output.

The initial size/path ranking included setters. One setter's inferred `s8`
argument caused an extra stack store under IDO. The final ranking prioritizes
empty returns among equal-size owners: `(size, empty-return first, assembly
path)`. There are 114 eight-byte empty returns; the first 100 are the final
batch. Preliminary candidates remain local in `.analysis/`.

## Reproduce

Place the user's ROM at `baseroms/jp/baserom.z64`. Its SHA-256 must be
`ed9f7cd7da795467c1e2b08ed1f878ff5aed906eae9ffe252074aef7a6703d8b`.

```sh
python3 -m venv .venv
.venv/bin/python -m pip install -r requirements-mapping.txt
gh repo clone matt-kempster/m2c tools/m2c
git -C tools/m2c checkout c632946b8cfbe8fce442b522dba92dfa72f1f317
.venv/bin/python -m splat split yamls/jp/mapping.yaml
.venv/bin/python tools/generate_pragmas.py baseroms/jp/baserom.z64
.venv/bin/python tools/generate_pragmas.py baseroms/jp/baserom.z64 --check
.venv/bin/python tools/m2c_easiest.py --cc /path/to/ido/5.3/cc
.venv/bin/python -m unittest discover -s tools -p 'test_*.py'
```

m2c was freshly cloned from upstream at the recorded commit. The compiler is
the existing native macOS IDO 5.3 toolchain used in the GS checkout, read without
modifying that checkout. Supply an equivalent toolchain when reproducing;
the evidence records every compiler-directory file hash.

`docs/pragma-evidence/m2c-easiest-100.json` records all 100 names, original
source/assembly paths, exact commands, candidate hashes, target hashes, compiled
function hashes, m2c revision, and compiler identity. The checker reads the
ELF function symbol's actual size and rejects relocations in its range. It
compares complete function bytes, not a similarity score or normalized words.
The extraction tests independently compare assembly listings against restored
ROM input. ROMs, extracted assembly, assets, compiler binaries, and objects
remain local and ignored.
