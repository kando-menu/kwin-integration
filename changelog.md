<!--
SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
SPDX-License-Identifier: CC-BY-4.0

Added      - for new features.
Changed    - for changes in existing functionality.
Deprecated - for soon-to-be removed features.
Removed    - for now removed features.
Fixed      - for any bug fixes.
Security   - in case of vulnerabilities.
-->

# Changelog of the KWin Integration Plugin for Kando

This changelog uses [semantic versioning](https://semver.org) and follows the rules of [Keep a Changelog](http://keepachangelog.com/).

## [KWin Integration 0.3.0](https://github.com/kando-menu/kwin-integration/releases/tag/v0.3.0)

**Release Date:** 2026-07-15

### :tada: Added

- Support for KWin 6.7. Thanks to [@Henry-Denny](https://github.com/Henry-Denny) for this contribution.
- Pre-built binaries for the current version of the upcoming Fedora 45.

## [KWin Integration 0.2.0](https://github.com/kando-menu/kwin-integration/releases/tag/v0.2.0)

**Release Date:** 2026-06-17

### :tada: Added

- A method to list all open windows, which is used by the "Focus Window" action to find the window to focus. This method retrieves the stacking order of windows from KWin and returns their titles and classes.
- A method to focus a window by its title and class. This method iterates through the open windows and activates the one that matches the given title and class.

## [KWin Integration 0.1.0](https://github.com/kando-menu/kwin-integration/releases/tag/v0.1.0)

**Release Date:** 2026-06-15

### :tada: Added

- The initial version of the KWin Integration plugin for Kando. It provides functionality similar to the Kando GNOME Shell extension, but for KDE Plasma. This includes:
  - Getting the current pointer position (mouse or stylus, depending on which was used last).
  - Getting the currently focused window.
