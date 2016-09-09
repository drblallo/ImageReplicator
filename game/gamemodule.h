#pragma once
#include "mechanics/enginemodule.h"
#include <vector>
#include "game/actions/teamprojectmanager.h"

using namespace mechanics;
namespace game
{
    class Colonizable;
    class GameModule : public EngineModule
    {
        public:
            GameModule();
            virtual ~GameModule();

            TeamProjectManager* getProjectManager(){return &projectManager;}
            void generatePlanet();
            inline const std::vector<Colonizable*>* getHoldings() const{return &ownedLocations;}
            inline Colonizable* getHolding(int t) const {return ownedLocations[t];}

        protected:
            virtual void tick();

        private:
            int tickTime;
            std::vector<Colonizable*> ownedLocations;
            TeamProjectManager projectManager;

    };
}
