# Stadium Zero bootstrap notes

Stadium Zero (Japanese-only original, ポケモンスタジアム) has no Western release.
This repository is a **Team Hippodrome original** scaffold following pret's
decompilation conventions; pret is not involved with this recompilation.

## Status

This is a mapping/static-analysis bootstrap. Standalone tools now record the
input hashes, resident and fragment storage layout, candidate executable sections,
and inspected indirect-flow target sets. See [the mapping notes](mappings/README.md)
and [the latest flow report](sections/refined/flow-and-gap-validation.md).

`make rom`, `make extract`, `make setup`, `make diff-init`,
and `make init` are intentionally unsupported and fail with a clear error. Do not
treat the current source tree as producing a buildable ROM.

## Open bootstrap gates

The following production-build gates remain open. The standalone mapping and
extraction checks do not establish a production build or independent dump identity.

- **ROM identity** — place a verified Japanese Stadium Zero `baserom.z64` and record
  its MD5 in `baseroms/jp/checksum.md5` (do not commit the ROM or retail assets).
  Validate the input ROM’s identity before extraction. Once building is
  implemented, compare the rebuilt ROM byte-for-byte against that verified
  input. Input checksum validation alone does not verify a build.
- **Compiler/flags** — confirm the original IDO version and per-file flags for Stadium
  Zero; do not assume Stadium 1 US settings apply.
- **Segment layout** — populate `yamls/jp/header.yaml` and `yamls/jp/rom.yaml` from a
  real split. `make extract` will remain unsupported until these exist.
- **Link order** — once split, seed `linker_scripts/jp/` and verify against a
  verified segment/link layout.
- **Verification gates, in order** —
  1. Validate the input ROM identity.
  2. Establish repeatable extraction.
  3. Verify rebuilt-ROM byte identity (the input MD5 is not a separate weaker milestone
     than full-ROM identity; it is one step in the chain).
  `requirements.txt` is provisional until the toolchain is confirmed.
