#pragma once
#include "render/linesobject.h"
#include "render/engineobject.h"

using namespace renderer;
class AppearingLines : public LinesObject, public EngineObject
{
public:
    AppearingLines(std::vector<float> *d);
    void Update();

private:
    int trueVCount;
    int timeElapsed;
    int vertexCount;

protected:
    virtual void Prerender();
    virtual void setBuffer(const void *pos, int size);
    int shaderTime;
};
