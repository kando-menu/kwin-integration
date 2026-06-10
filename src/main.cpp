#include <KPluginFactory>
#include <effect/effect.h>

#include "plugin/KandoKWinIntegrationPlugin.h"

class KWIN_EXPORT KandoIntegrationFactory : public KWin::EffectPluginFactory {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID EffectPluginFactory_iid FILE "metadata.json")
  Q_INTERFACES(KPluginFactory)

public:
  KWin::Effect *createEffect() const override {
    return new KandoKWinIntegrationPlugin();
  }

  bool isSupported() const override { return true; }
};

#include "main.moc"
