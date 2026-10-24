# m2c ranks 301–800

The next 500 unprocessed assembly owners were selected using the established
ascending `(size, empty-return first, assembly path)` ranking, excluding every
owner in the first two batches. All C in `candidates/m2c-batch-301-800/` is saved
verbatim from m2c commit `c632946b8cfbe8fce442b522dba92dfa72f1f317`, with
`--valid-syntax` and no context hints, manual corrections, or source variants.

| Result | Owners |
| --- | ---: |
| Exact function bytes | 200 |
| Byte mismatch | 135 |
| C compile failure | 165 |

Of the 200 matches, 61 matched directly in objects and 139 matched after GNU ld
resolved their address relocations. The matched owners cover 5,880 bytes and
range from 20 to 36 bytes each. All 300 misses remain excluded from production C.

The explicit registry now contains 448 C owners, with 4,996 owners remaining in
assembly. The production build compiled all 448, linked all 260 images, and
passed the complete-ROM hash gate. A direct `cmp` against the supplied input
also passed. The committed [receipt](production-build-receipt.json) and
[coverage](../COVERAGE.md) reflect this batch. Counts refer to conservative
assembly owners, not confirmed original functions or translation units.

Reproduce after extraction and toolchain setup:

```sh
.venv/bin/python tools/m2c_easiest.py --cc tools/ido5.3/cc --start 300 --count 500 --link
make rom
```

`docs/pragma-evidence/m2c-batch-301-800.json` records all 500 names, commands,
candidate/target/compiled hashes, linked comparison details, and failure
diagnostics. Its ROM gate field records the subsequent production validation;
the standalone candidate runner itself reports function-level evidence only.
The production [build constraints](production-build.md) remain unchanged.
