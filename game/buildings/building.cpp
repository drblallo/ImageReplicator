#include "building.h"

using namespace game;
Building::Building(QString n, int maxLevel): maxUpgrade(maxLevel), currentLevel(1) ,name(n)
{

}

Building::Building(const QString* n, int maxLevel): maxUpgrade(maxLevel), currentLevel(1) ,name(*n)
{

}

Building::~Building()
{

}

void Building::OnBuildingDowngraded()
{

}

void Building::OnBuildingRemoved()
{

}

void Building::OnBuildingUpgraded()
{

}

void Building::OnClicked()
{

}
