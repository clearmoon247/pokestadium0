# Stadium Zero bootstrap notes

Stadium Zero (Japanese-only original, ポケモンスタジアム) has no Western release and
no prior public decomp. This repository is a **Team Hippodrome original** scaffold
following pret's decompilation conventions; pret is not involved with this recompilation.

## Open bootstrap gates

The following must be resolved before a real build can be claimed. None are verified yet.

- **ROM identity** — place a verified Japanese Stadium Zero `baserom.z64` and record
  its MD5 in `baseroms/jp/checksum.md5` (do not commit the ROM or retail assets).
- **Compiler/flags** — confirm the original IDO version and per-file flags for Stadium
  Zero; do not assume Stadium 1 US settings apply.
- **Segment layout** — populate `yamls/jp/header.yaml` and `yamls/jp/rom.yaml` from a
  real split. `make extract` will fail until these exist.
- **Link order** — once split, seed `linker_scripts/jp/` and verify against the retail
  linker map.
- **Verification** — a green `make init` plus MD5 match is the bootstrap milestone; a
  full-ROM byte-identity build is a separate, later gate.
