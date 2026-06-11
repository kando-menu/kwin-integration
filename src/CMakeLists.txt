# -------------------------------------------------------------------------------------- #
#    _  _ ____ _  _ ___  ____                                                            #
#    |_/  |__| |\ | |  \ |  |    This file belongs to Kando, the cross-platform          #
#    | \_ |  | | \| |__/ |__|    pie menu. Read more on github.com/kando-menu/kando      #
#                                                                                        #
# -------------------------------------------------------------------------------------- #

# SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
# SPDX-License-Identifier: MIT

kcoreaddons_add_plugin(kandointegration INSTALL_NAMESPACE "kwin/effects/plugins")

target_sources(kandointegration PRIVATE
  main.cpp
  plugin/KandoKWinIntegrationPlugin.cpp
  dbus/KandoIntegrationAdaptor.cpp
)

target_link_libraries(kandointegration PRIVATE
  KWin::kwin
  Qt6::Core
  Qt6::DBus
)