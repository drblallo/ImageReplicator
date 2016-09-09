#include "mine.h"

using namespace game;
Mine::Mine(QString type) : Building(type+" mine", 4), production(1, type.toStdString())
{
    outputs.push_back(&production);

}


Mine::~Mine()
{

}
