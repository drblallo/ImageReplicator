#include "gamemodule.h"
#include <iostream>
#include "game/planets/planet.h"
#include "game/ui/holdingslist.h"
#include "game/planets/colonizable.h"

using namespace game;
GameModule::GameModule() : EngineModule(), tickTime(0), projectManager(1)
{
}

GameModule::~GameModule()
{

}

void GameModule::tick()
{
    tickTime++;
    std::cerr << "tick: " << tickTime << "\n";
}

void GameModule::generatePlanet()
{
    PlanetGenerationStat t;
    t.generate(1);
    ownedLocations.push_back(new Planet(5, t));
}
