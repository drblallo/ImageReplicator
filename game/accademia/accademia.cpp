#include "accademia.h"
#include "accademiagroups.h"
#include <cmath>

using namespace game;
Accademia::Accademia(AccademiaGroups* gr) : Building(QString("Accademia"), 10), group(gr), specialization(TeamTypeNone)
{
    if (gr)
        gr->addAccademia(this);
}

Accademia::~Accademia()
{
    if (group)
        group->removeAccademies(this);
}

AccademiaTeam Accademia::generateTeam() const
{
    std::default_random_engine generator;

    uniform_int_distribution<int> distribution(0, 4);
    uniform_real_distribution<float> distribution2(0, 1);

    int val = (distribution(generator) + getLevel() - 2);
    if (val <= 0)
        val = 1;
    unsigned short teamLevel(val);

    if (specialization != TeamTypeNone)
        return AccademiaTeam(QString("Nameless Team"), specialization, teamLevel + 1);

    return AccademiaTeam(QString("Nameless Team"),AccademiaTeamType(std::floor(TEAM_TYPE_MAX*distribution2(generator))), teamLevel);
}
