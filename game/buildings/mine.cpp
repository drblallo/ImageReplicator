#include "mine.h"
#include <iostream>

using namespace game;
Mine::Mine(QString type) : Building(type+" mine", 4), production(1, type.toStdString())
{
    std::cerr << "created mine\n";
    rawOutputs.push_back(&production);
}


Mine::~Mine()
{
    std::cerr << "removed mine\n";

}
