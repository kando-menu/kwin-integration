# -------------------------------------------------------------------------------------- #
#    _  _ ____ _  _ ___  ____                                                            #
#    |_/  |__| |\ | |  \ |  |    This file belongs to Kando, the cross-platform          #
#    | \_ |  | | \| |__/ |__|    pie menu. Read more on github.com/kando-menu/kando      #
#                                                                                        #
# -------------------------------------------------------------------------------------- #

# SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.20)

project(KandoKWinIntegration VERSION 0.1.0 LANGUAGES CXX)

# Generate compile_commands.json for editor tooling (clangd/VS Code IntelliSense).
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(KF6_MIN_VERSION "6.0.0")

find_package(ECM ${KF6_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(FeatureSummary)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.6 REQUIRED COMPONENTS Core DBus Widgets)
find_package(KWin REQUIRED COMPONENTS kwin)

add_subdirectory(src)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
