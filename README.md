# Pokémon Stadium Zero (JP)

A WIP decomp of Pokémon Stadium Zero (Japanese-only original, ポケモンスタジアム).
This is a **Team Hippodrome original** project; the layout and conventions follow
[pret](https://pret.github.io/)'s decompilation style, but pret is not involved with
this recompilation.

**Status: mapping and static-analysis bootstrap; not a buildable decomp.**
Resident/fragment storage mapping, evidence-labelled executable sections, and
indirect-flow analysis are implemented as standalone Python tools. No production
ROM build or toolchain bootstrap is implemented yet. `make rom`, `make extract`, `make setup`,
`make diff-init`, and `make init` all fail with a clear error by design. See
[docs/bootstrap.md](docs/bootstrap.md) for the open bootstrap gates and
[COVERAGE.md](COVERAGE.md) for the (unmeasured) coverage state.

## Completed analysis

- [Resident and fragment mappings](docs/mappings/README.md): input hashes,
  resident layout, compression/restoration rules, and 259 fragment images.
- [Initial executable-section map](docs/sections/stadium-zero-fragment-executable-sections.md):
  evidence spans and explicitly inferred text envelopes.
- [Latest indirect-flow and gap validation](docs/sections/refined/flow-and-gap-validation.md):
  217 static target sets across 288 recovered indirect sites; 71 runtime-dependent
  sites remain unresolved. The refined maps supersede the initial inventories.
- [Runtime capture watchlist](docs/sections/refined/runtime-watchlist.csv):
  unresolved-site registers and link-time addresses, not assumed runtime PCs.

The isolated analysis dependencies are pinned in `requirements-mapping.txt`.
The reports include reproduction commands and evidence from 28 passing tests.
No `/src` pragma inventory, Stadium 1/2 library match, or rebuilt-ROM identity
is claimed. All generated binary extraction output remains local and ignored.

It targets the following ROM:

* pokestadium0-jp.z64

Note: To use this repository, you must already have a rom for the game. Do not
commit the rom (or any dump of retail assets) to this repository.

# Prerequisites

The prerequisites and workflow below are **planned, not implemented** — this is a
bootstrap scaffold, and `requirements.txt` is provisional until the Stadium Zero
toolchain is confirmed.

Under Debian / Ubuntu, the eventual build is expected to need the standard
MIPS cross-compiler toolchain, Python 3, and a virtual environment. Install
suggested packages with:

```powershell
sudo apt update
sudo apt install make git build-essential binutils-mips-linux-gnu python3 python3-pip python3-venv
```

Python packages will be pinned in `requirements.txt` once the toolchain is
confirmed. In the meantime it lists only the provisional set of extraction
tools:

```powershell
python3 -m pip install -r requirements.txt
```

# To use (planned workflow — not implemented)

1. Place the Japanese Pokémon Stadium Zero rom into the repository's `/baseroms/jp/`
   folder as `baserom.z64`.
2. Set up tools and extract the rom: `make init`
3. Re-assemble the rom: `make`

These commands are currently stubs and will fail with a clear bootstrap error until
the gates in [docs/bootstrap.md](docs/bootstrap.md) are resolved.
