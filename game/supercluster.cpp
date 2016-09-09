#include "supercluster.h"
#include <iostream>
#include "gamesupercluster.h"
#include "gamewall.h"

using namespace game;
SuperCluster::SuperCluster(GameSuperCluster* superClusteer) :
    DottedObject(superClusteer->getDots()),
    superCluster(superClusteer)
{
    std::cout << superClusteer->getX() << ", " << superClusteer->getY() << "\n";
   /* QVector3D dir(1, 1, 0);
    if (superClusteer->getX() == 1)
        dir.setX(-1);
    if (superClusteer->getY() == 1)
        dir.setY(-1)*/;

    transform.setTranslation(-25, -25, 0);




}

SuperCluster::~SuperCluster()
{
}
