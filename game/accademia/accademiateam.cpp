#include "accademiateam.h"

using namespace game;
AccademiaTeam::AccademiaTeam(QString name, AccademiaTeamType t, unsigned short lvl) :
    teamName(name),
    type(t),
    skillLevel(lvl)
{

}

AccademiaTeam::AccademiaTeam()
{

}

AccademiaTeam::~AccademiaTeam()
{

}

int AccademiaTeam::getCost() const
{
    return (skillLevel*skillLevel);
}

QString AccademiaTeam::getTypeName() const
{
    switch (type) {
    case TeamTypeNone:
        return QString("None");
    case TeamTypeCivil:
        return QString("Civil");
    case TeamTypeEdile:
        return QString("Edile");
    case TeamTypeSpace:
        return QString("Space");
    case TeamTypeComputer:
        return QString("Computer");
    case TeamTypeEletronic:
        return QString("Elettronic");
    default:
        return QString("None");
    }

}

bool AccademiaTeam::operator==(const AccademiaTeam& rhs)
{
    if (getType() == rhs.getType() && getSkillLevel() == rhs.getSkillLevel())
        return true;
    return false;
}

bool AccademiaTeam::operator!=(const AccademiaTeam& rhs)
{
    if (getType() == rhs.getType() && getSkillLevel() == rhs.getSkillLevel())
        return false;
    return true;
}
