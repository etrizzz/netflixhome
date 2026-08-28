# Providers

Providers will be capability-scoped adapters. A manifest must declare allowed
domains and separate browser, detection, native playback, download, and
authentication capabilities. The core will reject undeclared capabilities and
will not inspect arbitrary page traffic. Phase 1 contains no external plugin
loader; that boundary is designed before provider implementation.
