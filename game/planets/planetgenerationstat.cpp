#include "planetgenerationstat.h"
#include <random>

using namespace game;
PlanetGenerationStat::PlanetGenerationStat() : food(0), iron(0)
{

}

void PlanetGenerationStat::generate(int seed)
{
    std::default_random_engine generator;
    generator.seed(seed);
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    food = dist(generator) * 10 + 5;
    iron = dist(generator) * 10 + 5;
}
