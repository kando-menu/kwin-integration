#include "KandoIntegrationAdaptor.h"

#include "../plugin/KandoKWinIntegrationPlugin.h"

KandoIntegrationAdaptor::KandoIntegrationAdaptor(KandoKWinIntegrationPlugin* plugin)
    : QDBusAbstractAdaptor(plugin), mPlugin(plugin) {}

QVariantMap KandoIntegrationAdaptor::GetWMInfo() const {
  return mPlugin->wmInfo();
}

QString KandoIntegrationAdaptor::Ping() const {
  return QStringLiteral("pong");
}
