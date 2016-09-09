#pragma once
#include "mechanics/characteristic.h"
#include "mechanics/stockpile.h"
#include "game/buildings/building.h"
#include <memory>

using namespace mechanics;
using namespace std;
namespace game
{
    class Colonizable
    {
        public:
            Colonizable(int size);
            virtual ~Colonizable();

            inline const std::string* getName() const {return &name;}
            virtual vector<StockPile*> getMinable();
            vector<shared_ptr<Building> > getBuildings();
            void addBuilding(shared_ptr<Building> build);
            void removeBuilding(shared_ptr<Building> build);
            void removeBuilding(int building);

        //########################################
        //#####         Privatizing          #####
        //########################################
            Colonizable(const Colonizable&) = delete;
            Colonizable& operator= (const Colonizable&) = delete;

        private:
            Characteristic size;
            string name;
            vector<shared_ptr<Building> > buildings;

    };
}
