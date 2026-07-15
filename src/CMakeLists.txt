# -------------------------------------------------------------------------------------- #
# _  _ ____ _  _ ___  ____                                                            #
# |_/  |__| |\ | |  \ |  |    This file belongs to Kando, the cross-platform          #
# | \_ |  | | \| |__/ |__|    pie menu. Read more on github.com/kando-menu/kando      #
# #
# -------------------------------------------------------------------------------------- #

# SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
# SPDX-License-Identifier: MIT

kcoreaddons_add_plugin(kandointegration INSTALL_NAMESPACE "kwin/effects/plugins")

target_sources(kandointegration PRIVATE
  main.cpp
  plugin/KandoKWinIntegrationPlugin.cpp
  dbus/KandoIntegrationAdaptor.cpp
  input/PointerInput.cpp
)

target_link_libraries(kandointegration PRIVATE
  KWin::kwin
  Qt6::Core
  Qt6::DBus
)

if(DEFINED KWin_VERSION AND KWin_VERSION VERSION_GREATER_EQUAL "6.4.0")
  target_compile_definitions(kandointegration PRIVATE
    KANDO_KWIN_HAS_TABLET_TOOL_AXIS_PROXIMITY_STRUCT_EVENTS)
elseif(DEFINED KWin_VERSION AND KWin_VERSION VERSION_GREATER_EQUAL "6.3.0")
  target_compile_definitions(kandointegration PRIVATE
    KANDO_KWIN_HAS_TABLET_TOOL_AXIS_PROXIMITY_TABLET_EVENT)
else()
  target_compile_definitions(kandointegration PRIVATE KANDO_KWIN_HAS_TABLET_TOOL_EVENT)
endif()

# KWin 6.7 changed EffectHandler::clientArea() and removed the screen argument.
if(DEFINED KWin_VERSION AND KWin_VERSION VERSION_GREATER_EQUAL "6.7.0")
  target_compile_definitions(kandointegration PRIVATE KANDO_KWIN_HAS_CLIENT_AREA_TWO_ARGS)
endif()