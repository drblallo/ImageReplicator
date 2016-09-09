#pragma once
#include "teamproject.h"

using namespace mechanics;
namespace game
{
    class Colonizable;
    class BuildMineAction : public TeamProject
    {
        public:
            BuildMineAction(Colonizable* planet, int target, QString name, TeamProjectManager *man);


        protected:
            virtual void OnEnd();
            Colonizable* targetPlanet;
            unsigned int targetMinable;
            virtual ~BuildMineAction();

    };
}
