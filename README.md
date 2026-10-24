# Pokémon Stadium Zero (JP)

A WIP decompilation of the Japanese-only original Pokémon Stadium
(ポケモンスタジアム), by **Team Hippodrome**. The project follows pret's layout
conventions; pret is not involved.

Two matching tracks currently live side by side:

- **Per-function matching in `src/`.** 2,803 functions are C that compiles to
  the ROM bytes (2,004 ported from the Stadium 1 decomp, 799 from m2c's first
  output), checked per function by `tools/check_functions.py`; 173 more are
  identified libultra. See [docs/matching.md](docs/matching.md).
- **Fixed-layout production build.** `make rom` reproduces the complete 16 MiB
  ROM byte-for-byte. It compiles **551 unmodified m2c functions** from
  `candidates/`, assembles the remaining **4,893 known code owners**, links the
  resident image and all 259 fragments, and reconstructs their original storage.
  See [docs/production-build.md](docs/production-build.md).

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
binaries, then extracts local assets and assembly. `make rom` compares by default
and produces `build/pokestadium0-jp.z64`. See [production build details and
constraints](docs/production-build.md) for setup, verification, and development.

The per-function checker uses the IDO 7.1 and 5.3 recompilations fetched by
`tools/get_ido.sh` into the ignored `tools/ido/`:

```sh
tools/get_ido.sh
python3 tools/check_functions.py
```

Do not commit ROMs or extracted retail assets.

## Progress and evidence

- [Coverage](COVERAGE.md): first-pass owner counts and bytes for both tracks.
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

The inventory is a first-pass assembly-owner scaffold, not recovered original
function or translation-unit boundaries. Runtime capture work remains paused.
