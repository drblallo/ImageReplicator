#include "teamproject.h"
#include <iostream>
#include "teamprojectmanager.h"

using namespace game;
TeamProject::TeamProject(int projectTime, int operationTime, QString n, TeamProjectManager* manag) :
    Timer(operationTime),
    GameProject(projectTime, n),
    manager(manag)
{
    if (!manag)
    {
        deleteMe = true;
        Action::uncall(project);
        return;
    }
    if (manager->addProject(this))
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
    manager->removeOperation(this);
    if (project)
    {
        Action::uncall(project);
        manager->removeProject(project);
    }
}

void TeamProject::onProjectCanceled()
{
    Action::uncall(this);
    manager->removeProject(project);
}

void TeamProject::OnProjectFinished()
{
    std::cerr << name.toStdString() << " created \n";
    manager->removeProject(project);
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
