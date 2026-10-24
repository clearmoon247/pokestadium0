#!/usr/bin/env python3
"""Install the pinned official IDO 5.3 and 7.1 static recomp releases into this checkout."""
import hashlib
import io
from pathlib import Path
import platform
import tarfile
import tempfile
import urllib.request

ROOT = Path(__file__).resolve().parents[1]
RELEASE = 'https://github.com/decompals/ido-static-recomp/releases/download/v1.2/'
ARCHIVES = {
    '5.3': {
        'macos': ('ido-5.3-recomp-macos.tar.gz', '5b1ca006ee4b158ffba0422fc3f00b9b330f9036f279bae2ea1b4703317ad9c0'),
        'linux': ('ido-5.3-recomp-linux.tar.gz', 'ab5c741561f80913d58c8b074771f23941a3edd312505a8ebed6d1dfeb65e506'),
        'linux-arm': ('ido-5.3-recomp-linux-arm.tar.gz', 'b6844c986fa65d7de4ce10b27583769a5ec7a88ae37a151f6dc66c929d3e1c92'),
    },
    # Game code (src/ outside the libraries) is built with IDO 7.1.
    '7.1': {
        'macos': ('ido-7.1-recomp-macos.tar.gz', '7f75570ed1ca14e6161b84b10743d440c685f27291bfbfaf87c6a82236553bc6'),
        'linux': ('ido-7.1-recomp-linux.tar.gz', '0d411696e178fcca34c31c3bf02011b928d7fd9c1fa7f8bf45070e0781b58e15'),
        'linux-arm': ('ido-7.1-recomp-linux-arm.tar.gz', 'd74443a65b1e7c92c7853c60a80de97b40c7b374eb0565d67b754d86bbf5f123'),
    },
}


def install(version):
    target = ROOT / ('tools/ido' + version)
    required = ('cc', 'cfe', 'uopt', 'ugen', 'as0', 'as1')
    if all((target / name).exists() for name in required):
        print(f'Using existing tools/ido{version} (override IDO_CC/IDO71_CC to use another toolchain)')
        return
    if target.exists():
        raise ValueError(f'incomplete tools/ido{version}; preserve or move it before reinstalling')
    system, machine = platform.system(), platform.machine().lower()
    if system == 'Darwin':
        key = 'macos'
    elif system == 'Linux' and machine in ('x86_64', 'amd64', 'aarch64', 'arm64'):
        key = 'linux-arm' if machine in ('aarch64', 'arm64') else 'linux'
    else:
        raise SystemExit('Unsupported host; supply IDO_CC, IDO71_CC and MIPS_BINUTILS_PREFIX manually')
    name, expected = ARCHIVES[version][key]
    print('Downloading pinned IDO v1.2:', name, flush=True)
    cache = ROOT / '.analysis/toolchain-download' / name
    if cache.exists():
        payload = cache.read_bytes()
    else:
        payload = urllib.request.urlopen(RELEASE + name, timeout=60).read()
    if hashlib.sha256(payload).hexdigest() != expected:
        raise ValueError('toolchain archive checksum differs')
    with tempfile.TemporaryDirectory(prefix='.ido-stage-', dir=ROOT / 'tools') as temporary:
        stage = Path(temporary) / ('ido' + version)
        stage.mkdir()
        with tarfile.open(fileobj=io.BytesIO(payload), mode='r:gz') as archive:
            for member in archive:
                # Official archives are flat. Reject paths, links, and overwrites.
                if not member.isfile() or Path(member.name).name != member.name:
                    raise ValueError('unexpected archive entry: ' + member.name)
                path = stage / member.name
                if path.exists():
                    raise ValueError('duplicate archive entry: ' + member.name)
                path.write_bytes(archive.extractfile(member).read())
                path.chmod(member.mode & 0o777)
        if not all((stage / name).exists() for name in required):
            raise ValueError('required compiler tools missing from archive')
        stage.rename(target)
    print(f'Installed verified IDO {version} v1.2')


def main():
    for version in ARCHIVES:
        install(version)


if __name__ == '__main__':
    main()
