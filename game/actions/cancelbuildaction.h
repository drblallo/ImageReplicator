#pragma once
#include "mechanics/action.h"

using namespace mechanics;
namespace game
{
    class BuildMineAction;
    class CancelBuildAction : public Action
    {
        public:
            CancelBuildAction(game::BuildMineAction *toCancel);

       protected:
            virtual void execute();
            virtual ~CancelBuildAction();

       private:
            BuildMineAction* action;

    };
}
