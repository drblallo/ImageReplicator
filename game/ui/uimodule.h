#pragma once
#include "mechanics/enginemodule.h"
#include "render/engineobject.h"
#include <mutex>

using namespace mechanics;
class MainWindow;
using namespace renderer;
namespace game
{
    class GameModule;
    class UIModule : public EngineModule, public EngineObject
    {
        public:
            UIModule(GameModule *module, MainWindow* w);
            virtual ~UIModule();
        protected:
            GameModule* module;
            MainWindow* mainWindow;
            virtual void tick();
            virtual void Update();
            bool toUpdate;
            std::mutex m;
    };
}
