<!--
SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
SPDX-License-Identifier: CC-BY-4.0
-->

# Changelog of the KWin Integration Plugin for Kando

## [KWin Integration 0.4.0](https://github.com/kando-menu/kwin-integration/releases/tag/v0.4.0)

**Release Date:** TBD

- The plugin now uses KWin's `InputSpy` instead of `InputFilter` to get the current pointer position. This allows getting the pointer position even during drag-and-drop operations, which was not possible before.

## [KWin Integration 0.3.1](https://github.com/kando-menu/kwin-integration/releases/tag/v0.3.1)

**Release Date:** 2026-08-07

- Rebuilt the plugin with the latest versions of Qt6, KWin, and KDE Frameworks. Functionality remains the same, feel free to use 0.3.0 if your KWin version is not yet compatible with this release.

## [KWin Integration 0.3.0](https://github.com/kando-menu/kwin-integration/releases/tag/v0.3.0)

**Release Date:** 2026-07-15

- Added support for KWin 6.7. Thanks to [@Henry-Denny](https://github.com/Henry-Denny) for this contribution.
- Added pre-built binaries for the current version of the upcoming Fedora 45.

## [KWin Integration 0.2.0](https://github.com/kando-menu/kwin-integration/releases/tag/v0.2.0)

**Release Date:** 2026-06-17

- Added a method to list all open windows, which is used by the "Focus Window" action to find the window to focus. This method retrieves the stacking order of windows from KWin and returns their titles and classes.
- Added a method to focus a window by its title and class. This method iterates through the open windows and activates the one that matches the given title and class.

## [KWin Integration 0.1.0](https://github.com/kando-menu/kwin-integration/releases/tag/v0.1.0)

**Release Date:** 2026-06-15

- This is the initial version of the KWin Integration plugin for Kando. It provides functionality similar to the Kando GNOME Shell extension, but for KDE Plasma. This includes:
  - Getting the current pointer position (mouse or stylus, depending on which was used last).
  - Getting the currently focused window.
