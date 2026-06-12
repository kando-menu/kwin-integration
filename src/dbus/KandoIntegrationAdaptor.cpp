//////////////////////////////////////////////////////////////////////////////////////////
//   _  _ ____ _  _ ___  ____                                                           //
//   |_/  |__| |\ | |  \ |  |    This file belongs to Kando, the cross-platform         //
//   | \_ |  | | \| |__/ |__|    pie menu. Read more on github.com/kando-menu/kando     //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

// SPDX-FileCopyrightText: Simon Schneegans <code@simonschneegans.de>
// SPDX-License-Identifier: MIT

#include "KandoIntegrationAdaptor.h"

#include "../plugin/KandoKWinIntegrationPlugin.h"

KandoIntegrationAdaptor::KandoIntegrationAdaptor(KandoKWinIntegrationPlugin* plugin)
    : QDBusAbstractAdaptor(plugin), mPlugin(plugin) {}

QVariantMap KandoIntegrationAdaptor::GetWMInfo() const { return mPlugin->getWMInfo(); }

QString KandoIntegrationAdaptor::Ping() const { return QStringLiteral("pong"); }
