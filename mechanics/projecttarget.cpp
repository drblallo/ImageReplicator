#include "projecttarget.h"

using namespace mechanics;
ProjectTarget::ProjectTarget(int baseTimeToCreate, QString n) :
    projectTime(baseTimeToCreate, std::string("base")),
    project(new Project(this, n)),
    name(n)
{

}

ProjectTarget::~ProjectTarget()
{
    if (project)
        project->target = NULL;
}

QString ProjectTarget::getDescriptiveName() const
{
    QString n(name);

    return n;
}

