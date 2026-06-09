# kwin-integration

Basic scaffold for a KDE/KWin binary plugin that exposes a queryable D-Bus API for Kando.

## Build

```bash
cmake -S . -B build
cmake --build build --config Release
cmake --install build --config Release
```

Required development packages include Qt6, ECM, KF6 CoreAddons, and KWin development files.
