#include "planet.h"

using namespace game;
Planet::Planet(int size, PlanetGenerationStat stats) :
    Colonizable(size),
    food(stats.food, std::string("food")),
    iron(stats.iron, std::string("iron"))
{

}

Planet::~Planet()
{

}

vector<StockPile*> Planet::getMinable()
{
    vector<StockPile*> c(Colonizable::getMinable());
    c.push_back(&food);
    c.push_back(&iron);
    return c;
}
