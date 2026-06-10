#pragma once

#include <QObject>
#include <QVariantMap>
#include <effect/effect.h>

class KandoIntegrationAdaptor;

class KandoKWinIntegrationPlugin : public KWin::Effect {
  Q_OBJECT

public:
  explicit KandoKWinIntegrationPlugin();
  ~KandoKWinIntegrationPlugin() override;

  QVariantMap wmInfo() const;

private:
  KandoIntegrationAdaptor *mAdaptor;
};
