#pragma once
#include "render/linesobject.h"
#include "render/engineobject.h"

using namespace renderer;
class AppearingLines : public LinesObject, public EngineObject
{
public:
    AppearingLines(std::vector<Dot> *d);
    void Update();

private:
    int trueVCount;
};
