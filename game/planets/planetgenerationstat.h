#pragma once
#include <string>

namespace game
{
    class PlanetGenerationStat
    {
        public:
            PlanetGenerationStat();
            float food;
            float iron;
            virtual void generate(int seed);
    };
}
