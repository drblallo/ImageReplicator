#include "teamprojectmanager.h"
#include <algorithm>
#include "teamproject.h"

using namespace game;
TeamProjectManager::TeamProjectManager(int max) : maxProjects(max)
{

}

bool TeamProjectManager::addProject(TeamProject *project)
{
    if (!project)
        return false;

    for (unsigned int a = 0; a < operations.size(); a++)
        if (operations[a] == project)
            return false;
    if (isMaxedOut())
        return false;

    operations.push_back(project);
    if (project->getProject())
        projects.push_back(project->getProject());
    return true;
}

void TeamProjectManager::removeOperation(TeamProject *p)
{
    operations.erase(remove(operations.begin(), operations.end(), p), operations.end());
}

void TeamProjectManager::removeProject(Project *p)
{
    projects.erase(remove(projects.begin(), projects.end(), p), projects.end());
}

TeamProject* TeamProjectManager::getMostAdvancedProject()
{
    if (operations.size() == 0)
        return NULL;

    TeamProject* p(operations[0]);
    for (unsigned int a = 1; a < operations.size(); a++)
    {
        if (p->getTimeToLive() <  operations[a]->getTimeToLive())
            p = operations[a];
    }
    return p;
}

vector<Project*> TeamProjectManager::getProjects ()
{
    vector<Project*> toBeReturned;
    for (unsigned int a = 0; a < projects.size(); a++)
    {
        if (projects[a]->isPending())
            toBeReturned.push_back(projects[a]);
    }
    return toBeReturned;
}

vector<TeamProject*> TeamProjectManager::getOperations()
{
    vector<TeamProject*> toBeReturned;
    for (unsigned int a = 0; a < operations.size(); a++)
    {
        if (operations[a]->isPending())
            toBeReturned.push_back(operations[a]);
    }
    return toBeReturned;

}
