#pragma once
#include "mechanics/characteristic.h"
#include "colonizable.h"
#include "mechanics/stockpile.h"
#include "planetgenerationstat.h"
#include <string>

namespace game
{
    class Planet : public Colonizable
    {
        public:
            Planet(int size, PlanetGenerationStat stats);
            virtual ~Planet();

            virtual vector<StockPile*> getMinable();

        //########################################
        //#####         Privatizing          #####
        //########################################
            Planet(const Planet&) = delete;
            Planet& operator= (const Planet&) = delete;

        protected:
            StockPile food;
            StockPile iron;


    };
}
