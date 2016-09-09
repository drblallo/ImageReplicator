#include "clusterscene.h"
#include "gamecluster.h"
#include "cluster.h"
#include "gamewall.h"
#include <functional>
#include <iostream>
#include "gamescenes.h"
#include "gamedata.h"
#include "render/input.h"
#include "render/device.h"
#include "render/glwidget.h"

using namespace game;
ClusterScene::ClusterScene() :
    cluster(NULL),
    cube(
        //QVector3D(1, 1, 0.2f),
        //QVector3D(0.5f, 0.5f, 0),
        //NULL
        )
    //targetSuperCluster(0)
{
    cube.hide(true);
    grid.hide(true);
    manager.setActive(false);
    //cube.setActive(false);
    //cube.getCube()->hide(true);

   // cube.setCallback(std::bind(&ClusterScene::clicked, this, placeholders::_1, placeholders::_2));
}

ClusterScene::~ClusterScene()
{
    if (isCurrentScene())
        tearDown();
}


void ClusterScene::tearDown()
{
    while (spawned.size() != 0)
    {
        delete spawned[spawned.size()-1];
        spawned.pop_back();
    }
    cube.hide(true);
    grid.hide(true);
    manager.setActive(false);
//    cube.setActive(false);
 //   cube.getCube()->hide(true);
    if (cluster)
    {
        delete cluster;
        cluster = NULL;
    }
}

void ClusterScene::setUp()
{
    //GameWall wall;
    //std::cout << "setting up supercluster "<< targetSuperCluster << "\n";
    if (!cluster)
        cluster = new Cluster(GameData::getData()->getCurrentCluster());
    cube.hide(false);
    grid.hide(false);
    manager.setActive(true);
    grid.setActive(true);
//    cube.setActive(true);
 //   cube.getCube()->hide(false);

    Camera3D* cam(renderer::Device::getGraphicWindow()->getCamera());
    cam->setTranslation(0, -30, 5);
    cam->setRotation(QQuaternion::fromEulerAngles(70, 0, 0));

}

void ClusterScene::update()
{
    if (Input::keyTriggered(Qt::Key_Escape) )//|| camera->translation().z() > 70)
    {
       // camera->setTranslation(-1*cluster->getTransform()->translation().x(),
         //                      -1*cluster->getTransform()->translation().y(),
           //                    camera->translation().z());
        GameScenes::getScenes()->superClusterScene.setAsCurrent();
        return;
    }

    std::vector<FloatingQuad>* ls(GameData::getData()->getCurrentCluster()->getQuads());
    QVector3D source(renderer::Device::getGraphicWindow()->getCamera()->translation()+ QVector3D(25, 25, 0));
    QVector3D dir(renderer::Device::getGraphicWindow()->getMouseForward());

    unsigned int target(0);
    float distance(source.distanceToPoint(ls->at(0).transform.translation()));
    for (unsigned int a = 1; a < ls->size(); a++)
    {
        if (ls->at(a).transform.translation().distanceToLine(source, dir) < distance)
        {
            distance = ls->at(a).transform.translation().distanceToLine(source, dir);
            target = a;
        }
    }
    cube.getTransform()->setTranslation(ls->at(target).transform.translation() - QVector3D(25, 25, 0));

    if (Input::buttonTriggered(Qt::LeftButton))
    {
        GameData::getData()->setCurrentGalaxy(target);
        if (GameData::getData()->getCurrentGalaxy())
            GameScenes::getScenes()->galaxyScene.setAsCurrent();
    }

}

void ClusterScene::clicked(int, int)
{
    std::cout << "clicked\n";

}

