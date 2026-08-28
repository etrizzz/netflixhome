# Wizza Media Hub

Wizza Media Hub is a privacy-first Linux desktop media center. This repository
currently contains the Phase 0 environment audit and the buildable Phase 1 Qt
Quick foundation. Media indexing and playback are deliberately introduced only
after this foundation passes its build and tests.

## Build on Linux Mint

```bash
./scripts/bootstrap-linux-mint.sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j"$(nproc)"
ctest --test-dir build --output-on-failure
./build/wizza-media
```

For development, use `cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug`.
The application is local-first, includes no telemetry, and does not implement
DRM circumvention or arbitrary web-media extraction.

See [the architecture](docs/ARCHITECTURE.md), [build notes](docs/BUILDING.md),
and [the audited environment](docs/ENVIRONMENT.md).
