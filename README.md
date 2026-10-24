# Pokémon Stadium Zero (JP)

A WIP decompilation of the Japanese-only original Pokémon Stadium
(ポケモンスタジアム), by **Team Hippodrome**. The project follows pret's layout
conventions; pret is not involved.

`make rom` builds the complete 16 MiB ROM byte-for-byte from `src/`. Every
source file is compiled whole with IDO through asm-processor; its C functions
and its `GLOBAL_ASM` owners link at their original addresses in the resident
image and all 259 fragments, and the fragments' original storage is rebuilt.

- **2,872 of 5,444 code owners are built from C** (Stadium 1 ports, m2c
  output, and 127 libultra functions from unmodified `lib/ultralib` sources), listed per owner in [docs/function-matches.csv](docs/function-matches.csv).
  See [docs/matching.md](docs/matching.md) and [docs/production-build.md](docs/production-build.md).
- 58 more functions have matching C that stays behind `#ifdef NON_MATCHING`
  until their file's `.rodata`/`.data` can be placed.
- 61 files place their own `.rodata`, `.data` or `.bss` at the ROM address. Other data, `.rodata`,
  microcode and other non-code ranges still come from the extracted ROM.

Original function boundaries, translation units, and compiler settings remain
under investigation.

## Build

Provide your own Japanese ROM as `baseroms/jp/baserom.z64`:

```text
SHA-256 ed9f7cd7da795467c1e2b08ed1f878ff5aed906eae9ffe252074aef7a6703d8b
```

Install Python 3, GNU make, and GNU MIPS binutils, then run:

```sh
make init
make rom
make test
```

`make init` installs pinned Python dependencies and verified official IDO 5.3
and 7.1 binaries into the ignored `tools/ido5.3/` and `tools/ido7.1/`, then
extracts local assets and assembly. `make rom` compares by default and produces
`build/pokestadium0-jp.z64`. See [production build details and
constraints](docs/production-build.md) for setup, verification, and development.

`tools/check_functions.py` is a faster per-function check of the C in `src/`
against the ROM, without linking.

Do not commit ROMs or extracted retail assets.

## Progress and evidence

- [Coverage](COVERAGE.md): first-pass owner counts and bytes built from C.
- [First matching pass](docs/matching.md): Stadium 1 ports and m2c output in
  `src/`, listed per owner in [function-matches.csv](docs/function-matches.csv).
- [Initial 100 m2c functions](docs/m2c-easiest-100.md): eight-byte empty returns.
- [Next 200 m2c attempts](docs/m2c-next-200.md): 148 matches and 52 misses.
- [Next 500 m2c attempts](docs/m2c-next-500.md): 200 matches and 300 misses.
- [Ranks 801–1000](docs/m2c-next-200-801-1000.md): 103 matches and 97 misses.
- [Production receipt](docs/production-build-receipt.json): complete-ROM identity.
- [Resident and fragment mappings](docs/mappings/README.md): storage and restoration.
- [Executable sections and flow](docs/sections/refined/flow-and-gap-validation.md):
  conservative code discovery, indirect sites, and unresolved boundaries.
- [Runtime capture watchlist](docs/sections/refined/runtime-watchlist.csv):
  unresolved-site registers and link-time addresses, not assumed runtime PCs.
- [Pragma scaffold](docs/pragma-bootstrap.md): 5,444 assembly owners. The
  production registry selects accepted C directly from candidate files.
- [Stadium 1/2 library overlap](docs/library-overlap/README.md): scoped exact-byte
  and address-masked comparisons with pinned donor revisions.
- [First library compiler test](docs/library-overlap/compiler-test/README.md):
  nine function bodies reproduced exactly using the Stadium 1 donor's production
  IDO 5.3 library recipe, with donor-ROM and Zero-ROM controls.
- [Review-only library candidates](candidates/libraries/batch1/README.md):
  four byte-identical donor translation units for those nine verified functions.

The inventory is a first-pass assembly-owner scaffold, not recovered original
function or translation-unit boundaries. Runtime capture work remains paused.
