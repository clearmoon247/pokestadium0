#!/bin/sh
# Download the IDO 7.1 and 5.3 static recompilations used by tools/check_functions.py
# into tools/ido/<os>/<version>/ (ignored by Git).
set -e
VERSION=v1.2
case "$(uname -s)" in
  Linux) OS=linux ;;
  Darwin) OS=macos ;;
  *) echo "unsupported host; download ido-*-recomp archives from https://github.com/decompals/ido-static-recomp/releases" >&2; exit 1 ;;
esac
ROOT=$(cd "$(dirname "$0")/.." && pwd)
for IDO in 7.1 5.3; do
  DEST="$ROOT/tools/ido/$OS/$IDO"
  if [ -x "$DEST/cc" ]; then continue; fi
  mkdir -p "$DEST"
  curl -sSL "https://github.com/decompals/ido-static-recomp/releases/download/$VERSION/ido-$IDO-recomp-$OS.tar.gz" | tar -xz -C "$DEST"
done
echo "IDO installed under tools/ido/$OS"
