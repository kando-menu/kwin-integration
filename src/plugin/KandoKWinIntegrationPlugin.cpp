#include "KandoKWinIntegrationPlugin.h"

#include <QDBusConnection>
#include <QDBusError>
#include <QDebug>

#include "../dbus/KandoIntegrationAdaptor.h"

namespace {
const auto kServiceName = QStringLiteral("menu.kando.KWinIntegration");
const auto kObjectPath = QStringLiteral("/menu/kando/KWinIntegration");
}  // namespace

KandoKWinIntegrationPlugin::KandoKWinIntegrationPlugin()
  : KWin::Effect(), mAdaptor(new KandoIntegrationAdaptor(this)) {
  auto bus = QDBusConnection::sessionBus();

  if (!bus.registerService(kServiceName)) {
    qWarning() << "Failed to register D-Bus service" << kServiceName
               << bus.lastError().message();
  }

  if (!bus.registerObject(kObjectPath, this)) {
    qWarning() << "Failed to register D-Bus object" << kObjectPath
               << bus.lastError().message();
  }
}

KandoKWinIntegrationPlugin::~KandoKWinIntegrationPlugin() {
  auto bus = QDBusConnection::sessionBus();
  bus.unregisterObject(kObjectPath);
  bus.unregisterService(kServiceName);
}

QVariantMap KandoKWinIntegrationPlugin::wmInfo() const {
  // TODO: Read active window, pointer, and work area from KWin runtime state.
  return {
      {QStringLiteral("windowName"), QString()},
      {QStringLiteral("appName"), QString()},
      {QStringLiteral("pointerX"), 0},
      {QStringLiteral("pointerY"), 0},
      {QStringLiteral("workAreaX"), 0},
      {QStringLiteral("workAreaY"), 0},
      {QStringLiteral("workAreaWidth"), 0},
      {QStringLiteral("workAreaHeight"), 0},
  };
}
