#include "wall.h"
#include <iostream>

using namespace game;
Wall::Wall(const std::vector<Dot>* stars) : DottedObject(stars)
{
    std::cout << stars->size() << "\n";
   // transform.setTranslation(0.0f, 0.0f, -5.0f);

}

Wall::~Wall()
{

}
