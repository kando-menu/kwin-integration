<!--
SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
SPDX-License-Identifier: CC-BY-4.0
-->

# KWin Integration for Kando

This KWin plugin is required for 🌸 [Kando](https://github.com/kando-menu/kando) on KDE Plasma under Wayland.
Via a D-Bus interface, it provides the name of the currently focused window, the current mouse pointer position, and a few more pieces of information required by Kando.

## ⬇️ Installation

For now, you have to build and install this plugin manually.
You can do this by running the following commands in a terminal:

```bash
git clone https://github.com/kando-menu/kwin-integration.git
cd kwin-integration
cmake -S . -B build
cmake --build build --config Release
sudo cmake --install build --config Release
```

Required development packages include Qt6, ECM, KF6 CoreAddons, and KWin development files.
For debian-based distributions, you can install these with:

```bash
sudo apt install extra-cmake-modules kwin-dev qt6-base-dev
```

## 🗒️ Changelog

See [changelog.md](./changelog.md) for a detailed list of changes.
