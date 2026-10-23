# Stadium Zero build bootstrap

The fixed-layout build is implemented and verified against the supplied JP ROM.
See [production build instructions](production-build.md) and the
[validation receipt](production-build-receipt.json).

Completed gates:

- Verified input SHA-256 before extraction.
- Repeatable resident/fragment extraction and conservative owner inventory.
- GNU assembly and image-specific linking of all 5,444 code owners.
- IDO compilation of 448 unmodified m2c functions in the default build.
- Reconstruction of compressed fragments from linked bytes and storage metadata.
- Complete rebuilt-ROM identity with comparison enabled by default.
- A changed-C negative control fails comparison; a clean restored build passes.

The original compiler's complete settings and original source-unit boundaries
remain open research questions. The current compiler configuration is measured
for the accepted candidates; it is not inferred for the entire game. Relayout,
retail compressor lineage, and runtime testing remain future work.

`make setup`, `make extract`, `make init`, `make rom`, and `make diff-init` now
perform their documented work. Mapping-only splat bins remain an analysis output;
the production build uses assets with known owner bytes removed, assembled/compiled
objects, generated per-image linker scripts, and the full-ROM comparison.
