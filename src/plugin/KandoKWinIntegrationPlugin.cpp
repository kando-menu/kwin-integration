//////////////////////////////////////////////////////////////////////////////////////////
//   _  _ ____ _  _ ___  ____                                                           //
//   |_/  |__| |\ | |  \ |  |    This file belongs to Kando, the cross-platform         //
//   | \_ |  | | \| |__/ |__|    pie menu. Read more on github.com/kando-menu/kando     //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

// SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
// SPDX-License-Identifier: MIT

#include "KandoKWinIntegrationPlugin.h"

#include <effect/effecthandler.h>
#include <effect/effectwindow.h>

#include <QDBusConnection>
#include <QDBusError>
#include <QDebug>

#include "../dbus/KandoIntegrationAdaptor.h"

namespace {
const auto kServiceName = QStringLiteral("menu.kando.KWinIntegration");
const auto kObjectPath  = QStringLiteral("/menu/kando/KWinIntegration");
}  // namespace

KandoKWinIntegrationPlugin::KandoKWinIntegrationPlugin()
    : KWin::Effect(), mAdaptor(new KandoIntegrationAdaptor(this)) {
  KWin::input()->installInputEventFilter(&mPointerInput);

  auto bus = QDBusConnection::sessionBus();

  if (!bus.registerService(kServiceName)) {
    qWarning() << "Failed to register D-Bus service" << kServiceName
               << bus.lastError().message();
  }

  if (!bus.registerObject(kObjectPath, this, QDBusConnection::ExportAdaptors)) {
    qWarning() << "Failed to register D-Bus object" << kObjectPath
               << bus.lastError().message();
  }
}

KandoKWinIntegrationPlugin::~KandoKWinIntegrationPlugin() {
  auto bus = QDBusConnection::sessionBus();
  bus.unregisterObject(kObjectPath);
  bus.unregisterService(kServiceName);

  KWin::input()->uninstallInputEventFilter(&mPointerInput);
}

QVariantMap KandoKWinIntegrationPlugin::getWMInfo() const {
  const auto pointerPos   = mPointerInput.lastPosition();
  const auto activeWindow = KWin::effects->activeWindow();

  const auto windowName = activeWindow ? activeWindow->caption() : QString();
  const auto appName    = activeWindow ? activeWindow->windowClass() : QString();

  QRectF workArea =
    KWin::effects->clientArea(KWin::MaximizeArea, pointerPos.toPoint(), nullptr);

  return {
    {QStringLiteral("windowName"), windowName},
    {QStringLiteral("appName"), appName},
    {QStringLiteral("pointerX"), qRound(pointerPos.x())},
    {QStringLiteral("pointerY"), qRound(pointerPos.y())},
    {QStringLiteral("workAreaX"), qRound(workArea.x())},
    {QStringLiteral("workAreaY"), qRound(workArea.y())},
    {QStringLiteral("workAreaWidth"), qRound(workArea.width())},
    {QStringLiteral("workAreaHeight"), qRound(workArea.height())},
  };
}

QVariantList KandoKWinIntegrationPlugin::getOpenWindows() const {
  QVariantList windows;

  for (const auto* window : KWin::effects->stackingOrder()) {
    if (!window || window->isDeleted() || !window->isManaged() ||
        window->isSpecialWindow() || window->isSkipSwitcher()) {
      continue;
    }

    const auto windowName = window->caption();
    const auto appName    = window->windowClass();

    if (windowName.isEmpty() && appName.isEmpty()) {
      continue;
    }

    windows.push_back(QVariantList{windowName, appName});
  }

  return windows;
}

bool KandoKWinIntegrationPlugin::focusWindow(const QString& windowName,
                                             const QString& appName) const {
  const auto windows = KWin::effects->stackingOrder();

  // Iterate top-most first so we focus the window the user most likely expects.
  for (auto it = windows.rbegin(); it != windows.rend(); ++it) {
    auto* window = *it;

    if (!window || window->isDeleted() || !window->isManaged()) {
      continue;
    }

    if (window->caption() == windowName && window->windowClass() == appName) {
      KWin::effects->activateWindow(window);
      return true;
    }
  }

  return false;
}
