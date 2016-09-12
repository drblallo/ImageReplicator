#pragma once
#include "mechanics/action.h"
#include "game/accademia/accademiateam.h"

using namespace mechanics;
namespace game
{
    class GameModule;
    class FireTeamAction : public Action
    {
        public:
            FireTeamAction(unsigned int target, GameModule* module, AccademiaTeam team);
            virtual ~FireTeamAction();

        protected:
            virtual void execute();

        private:
            unsigned int target;
            AccademiaTeam team;
            GameModule* module;

    };
}
