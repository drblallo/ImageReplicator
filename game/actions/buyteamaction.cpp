#include "buyteamaction.h"
#include "game/gamemodule.h"
#include "iostream"

using namespace game;
BuyTeamAction::BuyTeamAction(int t, GameModule* module) : Action(), gameModule(module), target(t)
{
    call(this);
}

BuyTeamAction::~BuyTeamAction()
{

}

void BuyTeamAction::execute()
{
    if (
            gameModule &&
            gameModule->getAccademiaGroup()->getTeams()->size() > target &&
            !gameModule->getAccademiaGroup()->isTeamBought(target)
       )
    {

        std::cerr << "executed";
        AccademiaTeam team(gameModule->getAccademiaGroup()->getTeam(target));
        if (gameModule->getMoney() >= team.getCost())
        {
            gameModule->removeMoney(team.getCost());
            gameModule->getAccademiaGroup()->removeTeam(target);
            gameModule->addTeam(team);
        }

    }
}
