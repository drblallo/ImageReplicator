#include "gamemodule.h"
#include <iostream>
#include "game/planets/planet.h"
#include "game/ui/holdingslist.h"
#include "game/planets/colonizable.h"

using namespace game;
GameModule::GameModule() : EngineModule(),money(100), tickTime(0), projectManager(1)
{
   blocked = true;
}

GameModule::~GameModule()
{

}

void GameModule::tick()
{
    tickTime++;
    std::cerr << "tick: " << tickTime << "\n";

    if (tickTime%360 == 1)
        yearlyTick();
}

void GameModule::generatePlanet()
{
    PlanetGenerationStat t;
    t.generate(1);
    ownedLocations.push_back(new Planet(5, t));
}

void GameModule::yearlyTick()
{
    playerAccademia.updateTeams();
}

void GameModule::removeTeam(unsigned int t)
{
    ownedTeams.erase(ownedTeams.begin() + t);
}

int GameModule::getIndexOfTeam(AccademiaTeam team) const
{
    for (unsigned int a = 0; a < ownedTeams.size(); a++)
    {
        if (team == ownedTeams[a])
            return a;
    }
    return -1;
}
