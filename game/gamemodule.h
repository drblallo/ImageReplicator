#pragma once
#include "mechanics/enginemodule.h"
#include <vector>
#include "game/actions/teamprojectmanager.h"
#include "accademia/accademiagroups.h"

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
            inline AccademiaGroups* getAccademiaGroup() {return &playerAccademia;}
            inline int getMoney() const {return money;}
            inline void addTeam(AccademiaTeam team){ownedTeams.push_back(team);}
            inline void removeMoney(int t) {money -= t;}
            inline const std::vector<AccademiaTeam>* getTeams() const {return &ownedTeams;}
            inline AccademiaTeam getTeam(int t) const {return ownedTeams[t];}
            int getIndexOfTeam(AccademiaTeam team) const;
            void removeTeam(unsigned int t);

        protected:
            virtual void tick();

        private:
            void yearlyTick();

            int money;

            unsigned long tickTime;
            std::vector<Colonizable*> ownedLocations;
            std::vector<AccademiaTeam> ownedTeams;
            TeamProjectManager projectManager;
            AccademiaGroups playerAccademia;

    };
}
