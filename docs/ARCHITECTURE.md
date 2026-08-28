# Architecture

## Principles

Wizza Media Hub uses a layered, local-first architecture. QML owns presentation
and interaction only; C++20 services own state and business rules. Long-running
work never blocks the GUI thread. Services are constructed by
`ApplicationController`, rather than accessed through a mutable global service
locator.

## Layers and dependency direction

```text
Qt Quick UI -> ApplicationController -> domain services -> adapters
                                              |            |-- SQLite
                                              |            |-- libmpv
                                              |            `-- FFprobe
                                              `-- immutable domain values
```

The initial controller exposes only application identity and settings. Future
phases add database, library, player, browser, provider, disc, and platform
services in that order. Each adapter has an interface suitable for focused Qt
Test coverage.

## Data and concurrency

SQLite is the source of truth for the library and playback state. Migrations are
transactional and versioned. Scans, probing, metadata, networking, and image
generation run in bounded workers and return value objects to the UI thread.
Models are paginated so poster memory usage is bounded for large libraries.

## Playback boundary

The player uses the libmpv client API and an embedded render context; it never
starts an external mpv process as its primary backend. FFprobe is an asynchronous
inspection adapter, not a decoder. Hardware acceleration is selected at runtime
with safe software fallback.

## Web trust boundary

Ordinary pages remain inside Qt WebEngine. Native media handoff is capability
based and is disabled unless a known provider, localhost source, or explicitly
user-controlled source authorizes detection and playback. Suspected DRM is never
handed to libmpv. Tokens, cookies, credentials, authorization headers, and signed
URLs are excluded from persistence and sanitized in logs.

## Persistent locations

Qt standard locations resolve configuration, cache, data, and state paths; no
home directory is hard-coded. Logging is local, rotated, and telemetry-free.
