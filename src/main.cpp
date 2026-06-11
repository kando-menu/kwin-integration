//////////////////////////////////////////////////////////////////////////////////////////
//   _  _ ____ _  _ ___  ____                                                           //
//   |_/  |__| |\ | |  \ |  |    This file belongs to Kando, the cross-platform         //
//   | \_ |  | | \| |__/ |__|    pie menu. Read more on github.com/kando-menu/kando     //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

// SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
// SPDX-License-Identifier: MIT

#include <effect/effect.h>

#include <KPluginFactory>

#include "plugin/KandoKWinIntegrationPlugin.h"

class KWIN_EXPORT KandoIntegrationFactory : public KWin::EffectPluginFactory {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID EffectPluginFactory_iid FILE "metadata.json")
  Q_INTERFACES(KPluginFactory)

 public:
  KWin::Effect* createEffect() const override { return new KandoKWinIntegrationPlugin(); }

  bool isSupported() const override { return true; }
};

#include "main.moc"
