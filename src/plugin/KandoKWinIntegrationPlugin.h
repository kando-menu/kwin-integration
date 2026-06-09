#pragma once

#include <effect/effect.h>
#include <QVariantMap>

class KandoIntegrationAdaptor;

class KandoKWinIntegrationPlugin : public KWin::Effect {
  Q_OBJECT

 public:
  explicit KandoKWinIntegrationPlugin();
  ~KandoKWinIntegrationPlugin() override;

  QVariantMap wmInfo() const;

 private:
  KandoIntegrationAdaptor* mAdaptor = nullptr;
};
