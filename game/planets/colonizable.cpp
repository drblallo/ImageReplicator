#include "colonizable.h"
#include <string>
#include <algorithm>
#include "mechanics/rawbonus.h"
#include <iostream>

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
    if (size <= buildings.size())
        return;

    buildings.push_back(build);

    std::cerr << "added building with modifiers count: " << build->getRawModifiers()->size()<< "\n";
    for (unsigned int a = 0; a < build->getRawModifiers()->size(); a++)
    {
        std::cerr << "adding raw modifier " << *build->getRawModifiers()->at(a)->getDescription() << "\n";
        Characteristic* c(addOutput(*build->getRawModifiers()->at(a)->getDescription()));
        c->addRawBonus(build->getRawModifiers()->at(a));
        std::cerr << "for characteristc: " << *c->getName() << "\n";
    }
    for (unsigned int a = 0; a < build->getPercentModifiers()->size(); a++)
    {
        std::cerr << "adding percent modifier " << *build->getPercentModifiers()->at(a)->getDescription() << "\n";
        Characteristic* c(addOutput(*build->getPercentModifiers()->at(a)->getDescription()));
        c->addRawBonus(build->getPercentModifiers()->at(a));
    }
}

Characteristic* Colonizable::addOutput(string output)
{
    Characteristic* c(hasOutPut(output));
    if (c != NULL)
        return c;

    outputs.push_back(Characteristic(0, output));
    return &outputs[outputs.size()-1];
}

Characteristic* Colonizable::hasOutPut(string outPutName)
{
    for (unsigned int a = 0; a < outputs.size(); a++)
    {
        if (*outputs[a].getName() == outPutName)
            return &(outputs[a]);
    }
    return NULL;
}

void Colonizable::removeBuilding(shared_ptr<Building> build)
{
    buildings.erase(remove(buildings.begin(), buildings.end(), build), buildings.end());
}

void Colonizable::removeBuilding(int building)
{
    buildings.erase(buildings.begin() + building);
}
