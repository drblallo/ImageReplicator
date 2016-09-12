#pragma once
#include <QString>

namespace game
{
    enum AccademiaTeamType
    {
        TeamTypeNone,
        TeamTypeCivil,
        TeamTypeEdile,
        TeamTypeSpace,
        TeamTypeComputer,
        TeamTypeEletronic,
        TEAM_TYPE_MAX
    };

    class AccademiaTeam
    {
        public:
            AccademiaTeam(QString name, AccademiaTeamType t, unsigned short lvl);
            AccademiaTeam();
            ~AccademiaTeam();

            inline const QString* getName() const {return &teamName;}
            QString getTypeName() const;
            inline AccademiaTeamType getType() const {return type;}
            inline unsigned short getSkillLevel() const {return skillLevel;}
            int getCost() const;
            bool operator==(const AccademiaTeam& rhs);
            bool operator!=(const AccademiaTeam& rhs);

        private:
            QString teamName;
            AccademiaTeamType type;
            unsigned short skillLevel;

    };
}
