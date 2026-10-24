# Production ROM build

`make rom` builds a byte-identical Stadium Zero JP ROM from compiled C,
assembled instructions, extracted opaque assets, and retained storage metadata.
The default build uses 551 unmodified m2c functions and 4,893 assembly owners.
It links the resident image and all 259 fragment images independently, preserving
the fragments that share link addresses. The verified output is 16,777,216 bytes:

```text
SHA-256 ed9f7cd7da795467c1e2b08ed1f878ff5aed906eae9ffe252074aef7a6703d8b
```

## Setup and commands

Install Python 3, GNU make, and GNU MIPS binutils (`mips-linux-gnu-as`, `ld`,
`objcopy`, `nm`). Put the privately supplied ROM at `baseroms/jp/baserom.z64`.

```sh
make init       # pinned Python packages, IDO, extraction
make rom        # COMPARE=1 by default; rebuilds objects and links every image
make test       # assembly regeneration check and repository tests
make coverage   # regenerate coverage from the verified receipt
```

`make setup` downloads the official `decompals/ido-static-recomp` v1.2 IDO 5.3
archive, verifies a pinned SHA-256, and installs it under ignored `tools/ido5.3`.
macOS and Linux x86-64/ARM64 archives are supported; native validation was on
macOS ARM64. Override `IDO_CC`, `MIPS_BINUTILS_PREFIX`, `PYTHON`, or `JOBS` through
make variables or a local `.make_options`. Python dependencies are pinned by
`requirements-mapping.txt`.

The build does not need m2c installed. To generate further candidates, clone
`matt-kempster/m2c` into ignored `tools/m2c` and use `tools/m2c_easiest.py`.
m2c is the only C generation engine used by these batches.

Output is `build/pokestadium0-jp.z64`. Per-image ELF objects, generated linker
scripts, and maps live under `build/production/`. `make diff-init` builds these
artifacts. `make clean` removes build output while preserving private extraction
and tools; `make distclean` preserves them as well. `make rom ASM_ONLY=1` rebuilds
all 5,444 owners from assembly as an independent baseline.

## What the gate verifies

Extraction validates the supplied ROM hash and the established mapping. It
removes every known owner interval from the extracted image assets, replacing
those bytes with zero. The linker includes only opaque gaps from these files;
all owner bytes must come from a newly compiled or assembled object. Tests check
that all 5,444 owner intervals are erased. Unknown ranges, boot code outside the
owner inventory, data, microcode, and resource-only images remain opaque assets.

The linker places each owner at its established image-relative address and
asserts its size. A C object's trailing alignment bytes may be trimmed only
when all trimmed bytes are zero. Address-bearing symbols retain their encoded
link addresses. GNU assembler syntax normalization preserves `addu`/`or` move
aliases, control registers, division instructions, and 64-bit transfers; no
raw-word fallback substitutes for assembly instructions.

For compressed fragments, extraction retains Yay0 masks, backreference topology,
wrapper metadata, restoration placeholders, and padding, while clearing all
literal bytes and restoration values. The builder emits literals and restored
words from the linked image and verifies every backreference. It then decodes
the result independently to check that it restores to the linked bytes. It
does not copy the original compressed code into the output.

The default gate checks every linked image hash and the complete ROM hash.
`build/production/receipt.json` records the result, compiler/binutils identity,
registry hash, source hashes, and build-tool hashes. A build invalidates the
previous receipt before compiling, so a failed run cannot leave a success receipt.
The committed `docs/production-build-receipt.json` is the reviewed validation
snapshot. A direct `cmp` also verified the final ROM against the supplied input.

A negative control replaced one accepted function with different m2c-generated
C of the same function size. The compiler consumed it, the linked resident
image changed, and the default comparison failed. Restoring the original C and
building after `make clean` passed. This checks that C edits affect the actual
output and that the build has no fallback to retail owner bytes.

## Current constraints

This is a fixed-layout build. Owner sizes and image addresses are held constant;
matching code changes can be promoted by adding their paths to
`config/jp/matching.json` and passing the full ROM gate. Only that explicit
registry selects C for production; failed candidates are excluded.

`COMPARE=0` permits nonidentical fixed-layout output, but an owner size change or
an edit incompatible with the retained compression topology fails explicitly.
General relayout and a compressor matching the retail encoder are future work.
The original compiler settings and original function/translation-unit boundaries
remain unconfirmed beyond the individual candidates that now pass the full ROM
gate. No runtime or emulator acceptance is claimed.

Private ROMs, extracted assets and assembly, compiler binaries, and build output
are ignored and must not be committed. CI runs synthetic storage/assembler tests
without a ROM; full-ROM verification requires the private local input.
