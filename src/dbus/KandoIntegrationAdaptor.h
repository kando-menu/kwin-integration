#pragma once

#include <QDBusAbstractAdaptor>
#include <QObject>
#include <QVariantMap>

class KandoKWinIntegrationPlugin;

class KandoIntegrationAdaptor : public QDBusAbstractAdaptor {
  Q_OBJECT
  Q_CLASSINFO("D-Bus Interface", "menu.kando.KWinIntegration1")

public:
  explicit KandoIntegrationAdaptor(KandoKWinIntegrationPlugin *plugin);

public Q_SLOTS:
  QVariantMap GetWMInfo() const;
  QString Ping() const;

private:
  KandoKWinIntegrationPlugin *mPlugin;
};
