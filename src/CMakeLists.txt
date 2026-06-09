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