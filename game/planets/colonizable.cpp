#include "colonizable.h"
#include <string>
#include <algorithm>

using namespace game;
Colonizable::Colonizable(int size) : size(size, std::string("Size")), name("Colonizable")
{

}

Colonizable::~Colonizable()
{

}

vector<StockPile*> Colonizable::getMinable()
{
    vector<StockPile*> t;
    return t;
}

vector<shared_ptr<Building> > Colonizable::getBuildings()
{
    return buildings;
}

void Colonizable::addBuilding(shared_ptr<Building> build)
{
    for (unsigned int a = 0; a < buildings.size(); a++)
        if (build.get() == buildings[a].get())
            return;
    if (size > buildings.size())
        buildings.push_back(build);
}

void Colonizable::removeBuilding(shared_ptr<Building> build)
{
    buildings.erase(remove(buildings.begin(), buildings.end(), build), buildings.end());
}

void Colonizable::removeBuilding(int building)
{
    buildings.erase(buildings.begin() + building);
}
