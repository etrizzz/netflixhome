# Phase 0 environment audit

Audit executed on 2026-08-28 before implementation.

| Component | Detected value |
| --- | --- |
| Distribution | Ubuntu 24.04.4 LTS (Noble), container rather than Linux Mint |
| Kernel | Linux 6.18.35 x86_64 |
| CMake | 3.28.3 |
| GCC | 13.3.0 |
| pkg-config | 1.8.1 |
| mpv / libmpv | Not installed |
| FFmpeg / ffprobe | Not installed |
| Qt 6 development packages | Not installed / not visible to pkg-config |

The required audit commands (`cat /etc/os-release`, `uname -a`, tool version
commands, and a pkg-config component check) were executed. An installation
attempt through APT failed because the execution environment's package proxy
returned HTTP 403 for the Ubuntu repositories. Consequently Phase 1 sources can
be configured only after dependencies are installed in a network-enabled host.
This is an environment limitation, not hidden by optional fake implementations.

Required packages are documented and installed idempotently by
`scripts/bootstrap-linux-mint.sh`. Hardware decoding and runtime codec support
must be audited again on the target Linux Mint machine.
