#include "gamecluster.h"
#include "gamedata.h"
#include "gamesupercluster.h"
#include <iostream>
#include "galaxygenerator.h"
#include "random"

using namespace game;
GameCluster::GameCluster(int superClusterAd, int clusterAdress) : adress(clusterAdress), superClusterAdress(superClusterAd)
{
    std::default_random_engine generator;
    generator.seed((superClusterAd*1000000)+(clusterAdress*1000));
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    GameData::getData()->setSuperCluster(superClusterAdress);
    //GameData::getData()->setCurrentCluster(clusterAdress);

    std::vector<Dot*>* clustDots(GameData::getData()->getCurrentSuperCluster()->getCluster(clusterAdress));
    std::cerr << "star in this are " << clustDots->size() << "\n";

    GalaxyGenerator gen(0);

    for (unsigned int a = 0; a < clustDots->size(); a++)
    {
        gen.setGeneration((superClusterAd*1000000)+(clusterAdress*1000)+a);

        Transform3D t;
        t.setTranslation(clustDots->at(a)->pos - QVector3D(getX(), getY(), 0));
        t.setTranslation(t.translation()*50);
        t.setScale(0.3f, 0.3f, 0.3f);
        t.setRotation(QQuaternion::fromEulerAngles(dist(generator)*360,dist(generator)*360,dist(generator)*360));
        galaxies.push_back(FloatingQuad(t, QVector4D(gen.getColor(), 1)));
        t.setScale(-0.3f, 0.3f, 0.3f);
        galaxies.push_back(FloatingQuad(t, QVector4D(gen.getColor(), 1)));
    }

}
