#include "project.h"
#include "projecttarget.h"

using namespace mechanics;
Project::Project(ProjectTarget* t, QString n) : Timer(t->getProjectTime()->calculate()), target(t), name(n)
{

}

Project::~Project()
{
    if (target)
    {
        /*if (dynamic_cast<Action*>(target) )
            if (getTimeToLive() > 0)
                Action::uncall(dynamic_cast<Action*>(target));*/
        if (getTimeToLive() > 0)
            target->onProjectCanceled();
        target->project = NULL;
    }
}

void Project::OnExpire()
{
    if (target)
    {
        target->OnProjectComplete();
    }
}

QString Project::getDescriptiveName() const
{
    QString s(name);
    s += "\t";
    s += QString::number(getTimeToLive());
    s += " Days";
    return s;
}
