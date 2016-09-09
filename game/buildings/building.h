#pragma once
#include "mechanics/characteristic.h"
#include <vector>
#include <QString>

using namespace mechanics;
using namespace std;
namespace game
{
    class Building
    {
        public:
        Building(QString n, int maxLevel);
        Building(const QString* n, int maxLevel);
        virtual ~Building();
        inline vector<Characteristic*>* getOutPuts(){return &outputs;}
        inline QString* getName(){return &name;}
        inline int getLevel(){return currentLevel;}
        inline int getMaxLevel(){return maxUpgrade;}

        protected:
        virtual void OnBuildingRemoved();
        virtual void OnBuildingUpgraded();
        virtual void OnBuildingDowngraded();
        virtual void OnClicked();
        vector<Characteristic*> outputs;
        int maxUpgrade;
        int currentLevel;
        QString name;

    };
}
