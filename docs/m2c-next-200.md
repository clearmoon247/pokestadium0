# m2c ranks 101–300

The next 200 unprocessed owners were selected using the same ascending
`(size, empty-return first, assembly path)` ranking. All C files in
`candidates/m2c-batch-101-300/` are unmodified m2c output from upstream commit
`c632946b8cfbe8fce442b522dba92dfa72f1f317`, using `--valid-syntax` and no
context hints, manual fixes, or source variants.

| Result | Owners |
| --- | ---: |
| Exact function bytes | 148 |
| Byte mismatch | 49 |
| Unresolved semantic library symbol (`fabsf`, `sqrtf`) | 2 |
| C compile failure | 1 |

Of the 148 matches, 101 matched directly in objects and 47 matched after
resolving their address relocations through GNU ld. The 52 misses remain
candidates; their production owners continue to use assembly.

The 148 new matches join the initial 100 in `config/jp/matching.json`. The
production build compiles all 248, assembles the remaining 5,196 owners, links
260 images, reconstructs storage, and passes the full-ROM comparison. See
[the production build](production-build.md) and its committed receipt. These
counts describe the current conservative assembly-owner inventory, not
confirmed original function boundaries or translation units.

Reproduce the bounded m2c batch after extraction:

```sh
.venv/bin/python tools/m2c_easiest.py --cc tools/ido5.3/cc --start 100 --count 200 --link
```

`docs/pragma-evidence/m2c-batch-101-300.json` records every candidate, command,
hash, comparison layer, and failure diagnostic. Its `full_rom_gate` field is
the historical state of the standalone candidate runner; the production
receipt records the subsequent ROM gate. The standalone runner used the
existing GS compiler; the production build independently reproduced the
matches with the pinned official IDO release installed in this checkout.
