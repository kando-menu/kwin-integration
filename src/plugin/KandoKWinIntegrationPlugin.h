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

#include <QVariantMap>

#include "input/PointerInput.h"

class KandoIntegrationAdaptor;

class KandoKWinIntegrationPlugin : public KWin::Effect {
  Q_OBJECT

 public:
  explicit KandoKWinIntegrationPlugin();
  ~KandoKWinIntegrationPlugin() override;

  QVariantMap getWMInfo() const;

 private:
  KandoIntegrationAdaptor* mAdaptor;
  PointerInput mPointerInput;
};
