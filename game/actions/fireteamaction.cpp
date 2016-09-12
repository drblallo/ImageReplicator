#include "fireteamaction.h"
#include "game/gamemodule.h"

using namespace game;
FireTeamAction::FireTeamAction(unsigned int t, GameModule* m, AccademiaTeam tea) :
    Action(),
    target(t),
    team(tea),
    module(m)
{
    call(this);
}

FireTeamAction::~FireTeamAction()
{

}

void FireTeamAction::execute()
{
   if (!module)
       return;

   if (module->getTeam(target) == team)
   {
       module->removeTeam(target);
   }
}
