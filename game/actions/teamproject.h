#pragma once
#include <QString>
#include "mechanics/timer.h"
#include "gameproject.h"
#include "game/accademia/accademiateam.h"

using namespace mechanics;
namespace game
{
    class GameModule;
    class TeamProject : public Timer, public GameProject
    {

        public:
            TeamProject(int projectTime, int operationTime, QString n, GameModule* m, AccademiaTeam team);
            virtual QString getDescriptiveName() const;

        protected:
            virtual void OnEnd() = 0;
            virtual ~TeamProject();
            virtual void onProjectCanceled();
            virtual void OnProjectStart();
            AccademiaTeam team;

        private:
            GameModule* module;
            virtual void OnExpire();
            virtual void OnProjectFinished();

    };
}
