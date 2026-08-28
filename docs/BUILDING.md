# Building

Install dependencies with `scripts/bootstrap-linux-mint.sh`, then configure with
CMake 3.24 or newer. A release and debug build use the standard commands shown
in the README. CMake intentionally requires every Phase 1 Qt component so a
partially provisioned build fails early and clearly.

The current container cannot download APT metadata (proxy HTTP 403); build and
runtime validation therefore need a Linux Mint host with repository access.
