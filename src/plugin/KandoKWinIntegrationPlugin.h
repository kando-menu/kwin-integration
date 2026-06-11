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

#include <QObject>
#include <QVariantMap>

class KandoIntegrationAdaptor;

class KandoKWinIntegrationPlugin : public KWin::Effect {
  Q_OBJECT

 public:
  explicit KandoKWinIntegrationPlugin();
  ~KandoKWinIntegrationPlugin() override;

  QVariantMap wmInfo() const;

 private:
  KandoIntegrationAdaptor* mAdaptor;
};
