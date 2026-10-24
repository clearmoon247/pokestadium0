"""Positive and negative controls for the unmasked object-byte verifier."""
import unittest
import hashlib
import json
from pathlib import Path

from verify_library_codegen import compare_bytes


class CodegenTests(unittest.TestCase):
    def test_identical(self):
        result = compare_bytes(b"\x03\xe0\x00\x08\0\0\0\0", b"\x03\xe0\x00\x08\0\0\0\0")
        self.assertTrue(result["byte_identical"])
        self.assertEqual(result["mismatched_word_offsets"], [])

    def test_changed_register_is_not_masked(self):
        result = compare_bytes(b"\x24\x02\0\x01", b"\x24\x03\0\x01")
        self.assertFalse(result["byte_identical"])
        self.assertEqual(result["mismatched_word_offsets"], ["0x0"])

    def test_changed_address_is_not_masked(self):
        result = compare_bytes(b"\x0c\0\0\x01", b"\x0c\0\0\x02")
        self.assertFalse(result["byte_identical"])

    def test_extra_nop_fails(self):
        result = compare_bytes(b"\x03\xe0\x00\x08\0\0\0\0", b"\x03\xe0\x00\x08")
        self.assertFalse(result["byte_identical"])
        self.assertEqual(result["mismatched_word_offsets"], ["0x4"])

    def test_candidate_sources_equal_verified_source_hashes(self):
        root = Path(__file__).resolve().parents[1]
        result = json.loads((root / "docs/library-overlap/compiler-test/results.json").read_text())
        for module, expected in result["source_hashes"].items():
            source = root / "candidates/libraries/batch1" / f"{module}.c"
            self.assertEqual(hashlib.sha256(source.read_bytes()).hexdigest(), expected)


if __name__ == "__main__":
    unittest.main()
