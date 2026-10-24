# Stadium Zero first library compiler test

The first bounded exact-overlap batch passed **9/9 raw function-byte comparisons** against both the Stadium 1 donor ROM and Stadium Zero, covering **1,372 compiled function bytes**. This establishes a scoped source-to-object-to-ROM result for the unchanged donor translation units, not a source landing or a complete Zero build.

Evidence is in `results.json`, `evidence/build.txt`, four object disassembly logs, `evidence/rebuild-reproducibility.txt`, and `evidence/tests.txt`. The reusable driver is `tools/verify_library_codegen.py`.

## Production recipe and provenance

The donor is [Stadium 1 revision 61ab5896988e55a1355dcaae7c4302785ea97f21](https://github.com/michiiik/pokestadium/tree/61ab5896988e55a1355dcaae7c4302785ea97f21). Its inspected [top-level Makefile](https://github.com/michiiik/pokestadium/blob/61ab5896988e55a1355dcaae7c4302785ea97f21/Makefile) passes `CC_OLD`, the bundled `tools/ido/linux/5.3/cc`, into the libultra build. The library selects `VERSION=I_P`, `TARGET=libultra_rom`, and `-O3` for these selected libc and graphics modules.

The actual commands were obtained from and run through the donor's library Makefiles, not reconstructed using the main game's IDO 7.1 defaults. `make -B` forced every selected translation unit to rebuild, with `FIXUPS=1 COMPARE=0 CROSS=mips-linux-gnu- CC=../../tools/ido/linux/5.3/cc VERBOSE=1 COLOR=0`. `COMPARE=0` disables the library archive's unavailable reference-archive check; the separate ROM-backed positive controls below do not rely on that switch as proof.

All four selected modules used these compiler settings:

```text
-c -Wab,-r4300_mul -G 0 -nostdinc -Xcpluscomm
-fullwarn -woff 516,649,838,712
-mips2 -o32
-D_MIPS_SZLONG=32 -DF3DEX_GBI
-DBUILD_VERSION=7 -DBUILD_VERSION_STRING="2.0I_P"
-non_shared -DNDEBUG -D_FINALROM -O3
```

The include directories were the donor's unchanged `lib/ultralib/include`, `include/ido`, and `include/PR`. The donor fixups set the ELF o32 ABI flag, strip its dummy symbol and remove `.mdebug`; they do not patch function instructions. The tracked donor sources and compiler files were checked against `HEAD` before the run.

- **Donor ROM:** MD5 `ed1378bc12115f71209a77844965ba50`; SHA256 `502f6082a6436012a8b61419435dec1388869a90ed870e87e2d7bee88f831519`.
- **Zero ROM:** SHA256 `ed9f7cd7da795467c1e2b08ed1f878ff5aed906eae9ffe252074aef7a6703d8b`.
- **Object inspection:** pyelftools `0.32`, ELF32 big-endian MIPS validation, GNU MIPS binutils `2.45.90.20260125`.
- **Compiler identity:** donor-bundled IDO 5.3 toolchain, pinned by repository revision and SHA256s for `cc`, `cfe`, `uopt`, `ugen`, `as0`, and `as1` in `results.json`.

The compiler version statement follows the donor's production path/configuration and recorded binary hashes; it is not a recovered identity claim for Zero's original compiler. No substituted compiler, experimental compiler, source edits, isolated function rewrites, or optimization sweep were used.

## Results

Each function below has **zero relocations inside its ELF `STT_FUNC` extent**. The verifier compares the entire function byte sequence without masking instructions, addresses, registers, stack offsets, or constants.

| Unchanged donor source | Function | Zero owner | Function bytes | Donor ROM control | Zero result |
|---|---|---|---:|---|---|
| `lib/ultralib/src/libc/string.c` | `memcpy` | `func_80056690` | 44 | Exact | Exact |
| Same translation unit | `strlen` | `func_800566BC` | 40 | Exact | Exact |
| Same translation unit | `strchr` | `func_800566E4` | 64 | Exact | Exact |
| `lib/ultralib/src/libc/ldiv.c` | `ldiv` | `func_8005B9E0` | 132 | Exact | Exact |
| `lib/ultralib/src/gu/mtxutil.c` | `guMtxF2L` | `func_80053330` | 256 | Exact | Exact |
| Same translation unit | `guMtxIdentF` | `func_80053430` | 136 | Exact | Exact |
| Same translation unit | `guMtxL2F` | `func_800534E8` | 180 | Exact | Exact |
| `lib/ultralib/src/gu/mtxcatf.c` | `guMtxCatF` | `func_80055410` | 360 | Exact | Exact |
| Same translation unit | `guMtxXFMF` | `func_80055370` | 160 | Exact | Exact |

The `string.c` TU also preserves its donor function order: `memcpy`, `strlen`, `strchr` in the emitted object. Full translation units were compiled, rather than separately extracting function bodies, preserving the normal header/TU context.

### Padding and byproduct functions

The Zero owner extents for `strchr`, `ldiv`, `guMtxL2F`, and `guMtxCatF` are respectively 76, 144, 184, and 368 bytes, exceeding their compiler `STT_FUNC` sizes of 64, 132, 180, and 360 bytes. The extra 12, 12, 4, and 8 bytes are trailing zero alignment words after the terminal instruction and delay slot; the canonical-extent rule excludes them while preserving the delay slot. Function code identity therefore does not imply that the standalone `.text` section or entire owner extent can be dropped into Zero without layout work.

`ldiv.c` also emits `lldiv`, and `mtxutil.c` emits `guMtxIdent`. Those functions were compiled as normal TU byproducts but were not part of this nine-function exact-overlap batch, and no passing result is asserted for them. Relocations elsewhere in a TU do not invalidate relocation-free comparisons for the selected functions.

## Controls and reproducibility

The verifier first checks the donor revision, tracked source/toolchain cleanliness, and both ROM identities. For each selected function it requires exactly one prior unambiguous exact donor-to-Zero hit, locates the fresh ELF function by its real symbol and size, rejects any relocation within that body, compares against the donor ROM as a positive control, then independently compares against Zero.

Two forced production builds produced identical `results.json`, including complete object hashes and every function result. Both runs passed all nine donor controls and all nine Zero comparisons; `evidence/rebuild-reproducibility.txt` records the checksum check.

The local suite passed **50 tests**: the previous 45 tests plus four byte-verifier controls and a candidate-source hash check. Those controls require identical bytes to pass and ensure that changed register bits, changed call-address bits and an extra nop fail; they therefore guard against accidentally promoting masked or length-mismatched code into an exact match.

The review branch now carries byte-identical source copies under `candidates/libraries/batch1`, outside the active `src` scaffold. The driver verifies those copies against the pinned donor before rebuilding and records candidate hashes; copying candidates does not replace a pragma or establish a full-ROM landing.

The unmodified `mtxcatf.c` uses CRLF and generated IDO warning 513 for ignored carriage returns. Compilation completed successfully, and its selected functions passed both raw-byte oracles; the warning was retained in the build log rather than suppressed or repaired.

## Reproduction

From the Zero checkout, with the pinned donor revision under `.analysis/reference/pokestadium`, its bundled compiler, supplied local ROMs, `make`, GNU MIPS binutils and `requirements-overlap.txt` installed:

```powershell
python tools/verify_library_codegen.py `
    --stadium1-rom "path/to/Stadium1-USA.z64" `
    --zero-rom "baseroms/jp/baserom.z64"
python -m unittest discover -s tools -p "test_*.py" -v
```

The driver reruns the production recipe with `make -B` and saves commands, disassembly and verification metadata. ROM bytes, generated object files, extracted retail assets, and donor source files are not copied into the report bundle; pinned source locations and hashes suffice to reproduce the experiment.

## Interpretation and sanity check

**Observed:** unchanged donor source, headers and production library recipe generate these nine exact Zero function bodies. This makes them verified local source-reuse candidates rather than merely ROM-overlap candidates.

**Not established:** Zero's original compiler/SDK version, all other libultra routines, linked data/relocation behavior, a whole donor-ROM baseline, Zero's final translation-unit/segment layout, or a full rebuilt Zero ROM. A matching body does not uniquely identify a compiler version, and nine successful controls do not verify the entire library.

No active pragma replacement, library build integration or symbol rename is performed by this batch. Full-ROM baselines and attribution review remain required before active source integration; the Team Hippodrome recomp attribution is unchanged. The candidate sources and evidence are intended for a draft review PR, not a completed matching-decomp landing.
