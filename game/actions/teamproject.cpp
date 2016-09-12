#include "teamproject.h"
#include <iostream>
#include "teamprojectmanager.h"
#include "game/gamemodule.h"

using namespace game;
TeamProject::TeamProject(int projectTime, int operationTime, QString n, GameModule* m, AccademiaTeam t) :
    Timer(operationTime),
    GameProject(projectTime, n),
    team(t),
    module(m)
{
    if (!module)
    {
        deleteMe = true;
        Action::uncall(project);
        return;
    }
    if (module->getProjectManager()->addProject(this))
    {
        Action::call(project);
    }
    else
    {
        deleteMe = true;
        Action::uncall(project);
    }
}

TeamProject::~TeamProject()
{
    module->getProjectManager()->removeOperation(this);
    if (project)
    {
        Action::uncall(project);
        module->getProjectManager()->removeProject(project);
    }
}

void TeamProject::onProjectCanceled()
{
    Action::uncall(this);
    module->getProjectManager()->removeProject(project);
}

void TeamProject::OnProjectFinished()
{
    std::cerr << name.toStdString() << " created \n";
    module->getProjectManager()->removeProject(project);
    Action::call(this);
    deleteMe = false;
}

void TeamProject::OnExpire()
{
    std::cerr << name.toStdString() << " compleated \n";
    OnEnd();
}

QString TeamProject::getDescriptiveName() const
{
   QString s(name);
   s += "\t";
   s += QString::number(getTimeToLive());
   s += " Days";
    return s;
}

void TeamProject::OnProjectStart()
{
    int index(module->getIndexOfTeam(team));
    if (index >= 0)
    {
        module->removeTeam(index);
    }
}
