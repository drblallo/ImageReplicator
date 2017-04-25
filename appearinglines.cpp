#include "appearinglines.h"
#include "render/input.h"
#include "globaldefines.h"

AppearingLines::AppearingLines(std::vector<Dot> *d) : LinesObject(d), EngineObject()
{
    trueVCount = getVertexCount();
    vCount = 0;
}

void AppearingLines::Update()
{
    if (vCount < trueVCount)
        vCount = vCount + (trueVCount/GENERATION_DIVISOR);
    if (vCount > trueVCount)
        vCount = trueVCount;

    if (Input::keyPressed(Qt::Key_0))
    {
        vCount = 0;
    }
    if (Input::keyPressed(Qt::Key_1))
    {
        vCount = trueVCount;
    }
}
