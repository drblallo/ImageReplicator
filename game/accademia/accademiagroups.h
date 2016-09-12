#pragma once
#include <vector>
#include "accademiateam.h"

using namespace std;
namespace game
{
    class Accademia;
    class AccademiaGroups
    {
        public:
            friend class Accademia;
            AccademiaGroups();
            ~AccademiaGroups();
            void addAccademia(Accademia* accademia);
            void removeAccademies(Accademia* accademia);

            void removeTeam(unsigned int t);

            void updateTeams();
            inline const vector<Accademia*>* getAccademies() const {return &accademies;}
            inline Accademia* getAccademia(unsigned int accademia) const {return accademies[accademia];}
            inline const vector<AccademiaTeam>* getTeams() const {return &aviableTeams;}
            inline AccademiaTeam getTeam(unsigned int a) const {return aviableTeams[a];}
            inline bool isTeamBought(unsigned int target) const {return bought[target];}


        private:
            vector<Accademia*> accademies;
            vector<AccademiaTeam> aviableTeams;
            vector<bool> bought;

    };
}
