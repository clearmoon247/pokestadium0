# Pokémon Stadium Zero (JP)

A WIP decompilation of the Japanese-only original Pokémon Stadium
(ポケモンスタジアム), by **Team Hippodrome**. The project follows pret's layout
conventions; pret is not involved.

The fixed-layout production build now reproduces the complete 16 MiB ROM
byte-for-byte. It compiles **551 unmodified m2c functions**, assembles the
remaining **4,893 known code owners**, links the resident image and all 259
fragments, and reconstructs their original storage. Original function boundaries,
translation units, and compiler settings remain under investigation.

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
Do not commit ROMs or extracted retail assets.

## Progress and evidence

- [Coverage](COVERAGE.md): first-pass owner counts and bytes, tied to a ROM gate.
- [Initial 100 m2c functions](docs/m2c-easiest-100.md): eight-byte empty returns.
- [Next 200 m2c attempts](docs/m2c-next-200.md): 148 matches and 52 misses.
- [Next 500 m2c attempts](docs/m2c-next-500.md): 200 matches and 300 misses.
- [Ranks 801–1000](docs/m2c-next-200-801-1000.md): 103 matches and 97 misses.
- [Production receipt](docs/production-build-receipt.json): complete-ROM identity.
- [Resident and fragment mappings](docs/mappings/README.md): storage and restoration.
- [Executable sections and flow](docs/sections/refined/flow-and-gap-validation.md):
  conservative code discovery, indirect sites, and unresolved boundaries.
- [Pragma scaffold](docs/pragma-bootstrap.md): 5,444 assembly owners in 188 source
  files. The production registry selects accepted C directly from candidate files;
  these scaffold TODOs remain available for later source-unit recovery.

Only m2c generated the candidate C. No manual C corrections or permuter were used.
Runtime capture work remains paused; byte identity is the acceptance gate here.
