#pragma once
#include "game/buildings/building.h"
#include "game/accademia/accademiateam.h"
#include <random>

using namespace std;
namespace game
{
    class AccademiaGroups;
    class Accademia : public Building
    {
        public:
            friend class AccademiaGroups;
            Accademia(AccademiaGroups* group = NULL);
            virtual ~Accademia();

            AccademiaTeam generateTeam() const;

        private:
            AccademiaGroups* group;
            AccademiaTeamType specialization;

    };
}
