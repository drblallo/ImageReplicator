#include "accademiagroups.h"
#include <algorithm>
#include "accademia.h"
#include <iostream>

using namespace game;
AccademiaGroups::AccademiaGroups()
{

}

AccademiaGroups::~AccademiaGroups()
{
    while (accademies.size() != 0)
    {
        removeAccademies(accademies[accademies.size()-1]);
    }
}

void AccademiaGroups::removeAccademies(Accademia *accademia)
{
    if (accademia && accademia->group == this)
    {
        accademies.erase(remove(accademies.begin(), accademies.end(), accademia), accademies.end());
        accademia->group = NULL;
    }
}

void AccademiaGroups::addAccademia(Accademia *accademia)
{
    if (accademia)
    {
        if (accademia->group)
            accademia->group->removeAccademies(accademia);

        accademies.push_back(accademia);
        accademia->group = this;
    }
}

void AccademiaGroups::updateTeams()
{
    aviableTeams.clear();
    bought.clear();

    int teamCount(10*accademies.size());
    if (teamCount > 50)
        teamCount = 50;

    for (int a = 0; a < teamCount; a++)
    {
        std::default_random_engine generator;
        uniform_int_distribution<int> distribution(0, 1);

        aviableTeams.push_back(accademies[accademies.size()*distribution(generator)]->generateTeam());
        bought.push_back(false);
    }
    std::cerr << aviableTeams.size() << " generate teams\n";

}

void AccademiaGroups::removeTeam(unsigned int t)
{
    if (t >= aviableTeams.size())
        return;

    bought[t] = true;
}
