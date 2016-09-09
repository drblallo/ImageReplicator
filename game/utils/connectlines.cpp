#include "connectlines.h"
#include "render/device.h"

using namespace game;

ConnectLines::ConnectLines(std::vector<Dot>* points) : LinesObject(points)
{

    transform.setTranslation(0, 0, 0);
}

ConnectLines::~ConnectLines()
{

}


