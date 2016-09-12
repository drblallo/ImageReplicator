#include "buildmineaction.h"
#include "game/planets/colonizable.h"
#include <iostream>
#include "mechanics/stockpile.h"
#include "game/buildings/mine.h"


using namespace game;
BuildMineAction::BuildMineAction(Colonizable* p, int target, QString name, GameModule* m, AccademiaTeam t) :
    TeamProject(10, 10, name, m, t),
    targetPlanet(p),
    targetMinable(target)
{

}

BuildMineAction::~BuildMineAction()
{

}

void BuildMineAction::OnEnd()
{
    vector<StockPile*> piles(targetPlanet->getMinable());

    if (piles.size() <= targetMinable)
        return;

    StockPile* c(piles[targetMinable]);

    if (c->getValue() <= 0)
        return;

    shared_ptr<Building> pointer(new Mine(QString::fromStdString(*c->getName())));
    targetPlanet->addBuilding(pointer);
}


