#include "appearinglines.h"
#include "render/input.h"

AppearingLines::AppearingLines(std::vector<Dot> *d) : LinesObject(d), EngineObject()
{
    trueVCount = getVertexCount();
    vCount = 0;
}

void AppearingLines::Update()
{
    if (vCount < trueVCount)
        vCount = vCount + (trueVCount/1000);
    if (vCount > trueVCount)
        vCount = trueVCount;

    if (Input::keyPressed(Qt::Key_0))
    {
        vCount = 0;
    }
}
