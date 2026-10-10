#!/usr/bin/env python3
"""Focused checks for the mapping decoder and mapping-only extraction."""
import hashlib
import json
import struct
import unittest
from pathlib import Path

import yaml

from map_rom import inspect_fragment, trace_yay0

ROOT = Path(__file__).resolve().parent.parent


class MappingTests(unittest.TestCase):
    def test_literal_stream(self):
        stream = b"Yay0" + struct.pack(">3I", 3, 20, 20)
        stream += struct.pack(">I", 0xE0000000) + b"ABC"
        decoded, consumed = trace_yay0(stream)
        self.assertEqual(decoded, b"ABC")
        self.assertEqual(consumed, 23)

    def test_overlapping_backreference(self):
        stream = b"Yay0" + struct.pack(">3I", 7, 20, 22)
        stream += struct.pack(">I", 0xC0000000)
        stream += struct.pack(">H", 0x3001) + b"AB"
        decoded, consumed = trace_yay0(stream)
        self.assertEqual(decoded, b"ABABABA")
        self.assertEqual(consumed, 24)

    def test_bad_backreference_rejected(self):
        stream = b"Yay0" + struct.pack(">3I", 3, 20, 22)
        stream += struct.pack(">I", 0) + struct.pack(">H", 0x1000)
        with self.assertRaises(ValueError):
            trace_yay0(stream)

    def test_fragment_header_rejected(self):
        with self.assertRaises(ValueError):
            inspect_fragment(bytes(32))

    def test_manifest_extents(self):
        report = json.loads((ROOT / "docs/mappings/resident-fragments.json").read_text())
        self.assertEqual(len(report["fragments"]), 259)
        for fragment in report["fragments"]:
            start = int(fragment["rom_start"], 0)
            end = int(fragment["rom_consumed_end"], 0)
            self.assertLess(start, end)
            self.assertLessEqual(end, report["size"])
            self.assertLess(int(fragment["entry_offset"], 0),
                            int(fragment["reloc_offset"], 0))
        for left, right in zip(report["fragments"], report["fragments"][1:]):
            self.assertLessEqual(int(left["rom_consumed_end"], 0),
                                 int(right["rom_start"], 0))

    def test_splat_bins_reproduce_input_bytes(self):
        """This is extraction partition identity, NOT a compiled ROM build."""
        config = yaml.safe_load((ROOT / "yamls/jp/mapping.yaml").read_text())
        original = (ROOT / "baseroms/jp/baserom.z64").read_bytes()
        digest = hashlib.sha256()
        segments = config["segments"]
        self.assertEqual(segments[0][0], 0)
        self.assertEqual(segments[-1][0], len(original))
        for segment, following in zip(segments, segments[1:]):
            start, kind, name = segment
            end = following[0]
            self.assertEqual(kind, "bin")
            payload = (ROOT / "assets/mapping" / f"{name}.bin").read_bytes()
            self.assertEqual(payload, original[start:end], name)
            digest.update(payload)
        self.assertEqual(digest.hexdigest(), hashlib.sha256(original).hexdigest())


if __name__ == "__main__":
    unittest.main()
