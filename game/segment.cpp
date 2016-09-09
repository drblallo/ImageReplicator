#include "segment.h"
#include <iostream>
#include "gamesegment.h"

using namespace game;
Segment::Segment(GameSegment* segment) :
    DottedObject(segment->getDots()),
    floor(segment->getQuads())
{
    //std::cout << superClusteer->getX() << ", " << superClusteer->getY() << "\n";
   /* QVector3D dir(1, 1, 0);
    if (superClusteer->getX() == 1)
        dir.setX(-1);
    if (superClusteer->getY() == 1)
        dir.setY(-1)*/;

   // transform.setTranslation(-25, -25, 0);

}

Segment::~Segment()
{
}
