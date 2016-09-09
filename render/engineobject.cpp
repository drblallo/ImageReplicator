#include "engineobject.h"
#include "device.h"
#include "glwidget.h"
#include <vector>
#include <iostream>

using namespace renderer;

//########################################
//##### Constructors and Conversions #####
//########################################
EngineObject::EngineObject()
{
    if (Device::getGraphicWindow())
        Device::getGraphicWindow()->engineObjects.push_back(this);
    else
        std::cerr << "failed to attach to module" << "\n";

}

EngineObject::~EngineObject()
{

    std::vector<EngineObject*>* w(&Device::getGraphicWindow()->engineObjects);
    w->erase(std::remove(w->begin(), w->end(), this), w->end());
    w = (&Device::getGraphicWindow()->updateQueue);
    w->erase(std::remove(w->begin(), w->end(), this), w->end());
}

//########################################
//#####           Methods            #####
//########################################
void EngineObject::Update()
{

}
