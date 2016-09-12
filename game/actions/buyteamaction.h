#pragma once
#include "mechanics/action.h"

using namespace mechanics;
namespace game
{
    class GameModule;
    class BuyTeamAction : public Action
    {
        public:
            BuyTeamAction(int target, GameModule* module);
            virtual ~BuyTeamAction();

        protected:
            virtual void execute();

        private:
            GameModule* gameModule;
            unsigned int target;
    };
}
