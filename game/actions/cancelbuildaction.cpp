#include "cancelbuildaction.h"
#include "game/actions/buildmineaction.h"

using namespace game;
CancelBuildAction::CancelBuildAction(BuildMineAction* toCancel) : Action(), action(toCancel)
{

}

CancelBuildAction::~CancelBuildAction()
{

}

void CancelBuildAction::execute()
{
    Action::uncall(action->getProject());
    Action::uncall(action);
}
