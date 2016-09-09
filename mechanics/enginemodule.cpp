#include "enginemodule.h"
#include "mechanicsengine.h"

using namespace mechanics;
EngineModule::EngineModule()
{
    MechanicsEngine::getEngine()->addModule(this);
}

EngineModule::~EngineModule()
{
    MechanicsEngine::getEngine()->removeModule(this);
}
