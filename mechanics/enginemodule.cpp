#include "enginemodule.h"
#include "mechanicsengine.h"

using namespace mechanics;
EngineModule::EngineModule() : blocked(false)
{
    MechanicsEngine::getEngine()->addModule(this);
}

EngineModule::~EngineModule()
{
    MechanicsEngine::getEngine()->removeModule(this);
}
