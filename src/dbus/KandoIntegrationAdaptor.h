//////////////////////////////////////////////////////////////////////////////////////////
//   _  _ ____ _  _ ___  ____                                                           //
//   |_/  |__| |\ | |  \ |  |    This file belongs to Kando, the cross-platform         //
//   | \_ |  | | \| |__/ |__|    pie menu. Read more on github.com/kando-menu/kando     //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

// SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
// SPDX-License-Identifier: MIT

#pragma once

#include <QDBusAbstractAdaptor>
#include <QObject>
#include <QString>
#include <QVariantList>
#include <QVariantMap>

class KandoKWinIntegrationPlugin;

class KandoIntegrationAdaptor : public QDBusAbstractAdaptor {
  Q_OBJECT
  Q_CLASSINFO("D-Bus Interface", "menu.kando.KWinIntegration1")

 public:
  explicit KandoIntegrationAdaptor(KandoKWinIntegrationPlugin* plugin);

 public Q_SLOTS:
  QVariantMap GetWMInfo() const;
  QVariantList GetOpenWindows() const;
  bool FocusWindow(const QString& windowName, const QString& appName) const;
  QString Ping() const;

 private:
  KandoKWinIntegrationPlugin* mPlugin;
};
