#pragma once
#include "mechanics/projecttarget.h"

using namespace mechanics;
namespace game
{
    class GameProject : public ProjectTarget
    {
        public:
            GameProject(int time, QString n);

        protected:
            virtual void OnProjectFinished() = 0;
            virtual ~GameProject();

        private:
            virtual void OnProjectComplete();
    };
}
