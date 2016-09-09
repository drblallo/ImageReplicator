#pragma once
#include <vector>
#include "mechanics/project.h"

using namespace mechanics;
using namespace std;
namespace game
{
    class TeamProject;
    class TeamProjectManager
    {
        public:
            TeamProjectManager(int max);

            //accessors
            inline bool isMaxedOut() const
            {
                return (maxProjects <= projects.size());
            }
            inline unsigned int getMaxProjectsCount() const
            {
                return maxProjects;
            }
            vector<Project*> getProjects ();
            vector<TeamProject*> getOperations();



            TeamProject* getMostAdvancedProject();


            bool addProject(TeamProject* project);
            void removeOperation(TeamProject *p);
            void removeProject(Project *p);

        private:
            unsigned int maxProjects;
            vector<TeamProject*> operations;
            vector<Project*> projects;
    };
}
