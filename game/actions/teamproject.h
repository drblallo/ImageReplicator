#pragma once
#include <QString>
#include "mechanics/timer.h"
#include "gameproject.h"

using namespace mechanics;
namespace game
{
    class TeamProjectManager;
    class TeamProject : public Timer, public GameProject
    {

        public:
            TeamProject(int projectTime, int operationTime, QString n, TeamProjectManager* manager);
            virtual QString getDescriptiveName() const;

        protected:
            virtual void OnEnd() = 0;
            virtual ~TeamProject();
            virtual void onProjectCanceled();

        private:
            TeamProjectManager* manager;
            virtual void OnExpire();
            virtual void OnProjectFinished();

    };
}
