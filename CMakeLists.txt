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
find_package(KF6 ${KF6_MIN_VERSION} REQUIRED COMPONENTS CoreAddons)

find_program(QT_QMAKE_EXECUTABLE qmake)

if(NOT QT_QMAKE_EXECUTABLE)
    message(FATAL_ERROR "qmake is not found.")
endif()

execute_process(COMMAND ${QT_QMAKE_EXECUTABLE} -query QT_INSTALL_PLUGINS
    OUTPUT_VARIABLE QT_PLUGINS_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

if(QT_PLUGINS_DIR)
    message(STATUS "Qt6 plugin directory:" "${QT_PLUGINS_DIR}")
else()
    message(FATAL_ERROR "Qt6 plugin directory cannot be detected.")
endif()

add_subdirectory(src)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)

message(STATUS "Installing to: ${QT_PLUGINS_DIR}")
