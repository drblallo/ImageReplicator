#pragma once
#include "mechanics/characteristic.h"
#include "mechanics/rawbonus.h"
#include <vector>
#include <QString>

using namespace mechanics;
using namespace std;
namespace game
{
    class Building
    {
        public:
        friend class Colonizable;

        Building(QString n, int maxLevel);
        Building(const QString* n, int maxLevel);
        virtual ~Building();
        inline QString* getName(){return &name;}
        inline int getLevel(){return currentLevel;}
        inline int getMaxLevel(){return maxUpgrade;}
        inline vector<RawBonus*>* getRawModifiers() {return &rawOutputs;}
        inline vector<RawBonus*>* getPercentModifiers() {return &percentOutputs;}
        virtual QString getDescription() const;

        protected:
        virtual void OnBuildingRemoved();
        virtual void OnBuildingUpgraded();
        virtual void OnBuildingDowngraded();
        virtual void OnClicked();
        vector<RawBonus*> rawOutputs;
        vector<RawBonus*> percentOutputs;
        int maxUpgrade;
        int currentLevel;
        QString name;

    };
}
