//////////////////////////////////////////////////////////////////////////////////////////
//   _  _ ____ _  _ ___  ____                                                           //
//   |_/  |__| |\ | |  \ |  |    This file belongs to Kando, the cross-platform         //
//   | \_ |  | | \| |__/ |__|    pie menu. Read more on github.com/kando-menu/kando     //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

// SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
// SPDX-License-Identifier: MIT

#pragma once

#include <effect/effect.h>

#include <QVariantList>
#include <QVariantMap>

#include "input/PointerInput.h"

class KandoIntegrationAdaptor;

class KandoKWinIntegrationPlugin : public KWin::Effect {
  Q_OBJECT

 public:
  explicit KandoKWinIntegrationPlugin();
  ~KandoKWinIntegrationPlugin() override;

  QVariantMap getWMInfo() const;
  QVariantList getOpenWindows() const;
  bool focusWindow(const QString& windowName, const QString& appName) const;

 private:
  KandoIntegrationAdaptor* mAdaptor;
  PointerInput mPointerInput;
};
