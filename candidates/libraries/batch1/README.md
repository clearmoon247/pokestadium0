# First library candidate batch

These four translation units are byte-for-byte copies of the tested donor sources,
preserving their existing function names, file bytes, and notices. They are
**review-only candidates**, not active Zero source integration. Zero's existing
`src/1060.c` pragma owners remain unchanged.

## Provenance and verified scope

The donor is [michiiik/pokestadium at 61ab5896988e55a1355dcaae7c4302785ea97f21](https://github.com/michiiik/pokestadium/tree/61ab5896988e55a1355dcaae7c4302785ea97f21).
The original paths are under `lib/ultralib/src/`; the relative paths below are
preserved within this candidate directory. Existing copyright/provenance notices
remain intact, and no new licensing claim is made.

| Candidate translation unit | Verified function bodies | Zero pragma owners |
|---|---|---|
| `libc/string.c` | `memcpy`, `strlen`, `strchr` | `func_80056690`, `func_800566BC`, `func_800566E4` |
| `libc/ldiv.c` | `ldiv` | `func_8005B9E0` |
| `gu/mtxutil.c` | `guMtxF2L`, `guMtxIdentF`, `guMtxL2F` | `func_80053330`, `func_80053430`, `func_800534E8` |
| `gu/mtxcatf.c` | `guMtxCatF`, `guMtxXFMF` | `func_80055410`, `func_80055370` |

Nine selected functions reproduce 1,372 exact code bytes under the tested
Stadium 1 production library recipe. This is not evidence that Zero's original
compiler was IDO 5.3.

`ldiv.c` also contains `lldiv`, and `mtxutil.c` also contains `guMtxIdent`.
Those two TU byproducts are retained to preserve the tested context, but are not
part of the nine-function verification claim. Do not import whole modules and
silently count their byproducts as verified landings.

## Reproduction and dependencies

These files are not standalone host-C sources. They depend on the pinned donor's
normal SDK headers and library Makefiles; this PR does not vendor that entire
header tree or the compiler binaries.

From the Zero checkout, after installing `requirements-overlap.txt` and providing
the pinned donor clone, its compiler and GNU MIPS binutils:

```powershell
python tools/verify_library_codegen.py `
    --stadium1-rom "path/to/Stadium1-USA.z64" `
    --zero-rom "baseroms/jp/baserom.z64"
```

The driver first checks every candidate TU byte-for-byte against the donor,
then forces the donor's normal production compilation and compares the selected
function bodies against both ROMs without address masking. It records the
candidate/source/compiler/object hashes alongside each result.

See the [compiler test report](../../../docs/library-overlap/compiler-test/README.md)
for flags, controls, function sizes and alignment-padding distinctions.

## Gates before active source integration

- Recover Zero's production build, compiler configuration and library/header context.
- Preserve Zero's original function order, layout, trailing alignment and references;
  the donor's TU layout is not asserted to be Zero's original TU layout.
- Resolve and separately verify any additional functions carried by a full TU.
- Reproduce the applicable donor full-ROM baseline and establish the Zero linker,
  data and full-ROM identity verifier before replacing active pragmas.
- Review attribution and source provenance without changing Team Hippodrome's
  project authorship.

The decomp follows pret conventions; pret is not involved in the Team Hippodrome
recomp. No ROMs, extracted retail assets or generated assembly are included here.
