#include "gamesupercluster.h"
#include <random>
#include <cmath>
#include "gamedata.h"
#include <iostream>

using namespace game;
GameSuperCluster::GameSuperCluster(int adrs) : wallDots(GameData::getData()->getWall()->getSuperCluster(adrs)), adress(adrs)
{
    generate(adrs);
}


void GameSuperCluster::generate(int seed)
{
    std::default_random_engine generator;
    generator.seed(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1);

    QVector3D dir(1, 1, 0);
    if (getX() == 1)
        dir.setX(-1);
    if (getY() == 1)
        dir.setY(-1);
    dir = dir*25;
    dir = dir + QVector3D(25, 25, 0);

    for (unsigned int a = 0; a < wallDots->size(); a++)
    {
        float quantity(1+(distribution(generator)*7));
        for (int b = 0; b < quantity; b++)
        {
            QVector3D distorsion(distribution(generator)-0.5f, distribution(generator)-0.5f, distribution(generator)-0.5f);
            distorsion = distorsion*0.1f;
            Dot d(wallDots->at(a)->pos + distorsion + dir, wallDots->at(a)->col);
            dots.push_back(d);
        }

    }


    for (unsigned int a = 0; a < dots.size(); a++)
    {

        QVector3D translated(dots[a].pos );
        translated = QVector3D(translated.x(), translated.y(), 0);
        if (translated.x() < 50 && translated.y() < 50)
           ammassClusters[int(translated.x())][int(translated.y())].push_back(&(dots[a]));

    }
}
