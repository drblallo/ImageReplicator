#include "superclusterscene.h"
#include "gamesupercluster.h"
#include "supercluster.h"
#include "gamewall.h"
#include <functional>
#include <iostream>
#include "gamescenes.h"
#include "gamedata.h"
#include "render/input.h"
#include "render/device.h"
#include "render/glwidget.h"
#include "gamecluster.h"

using namespace game;
SuperClusterScene::SuperClusterScene() :
    superCluster(NULL),
    cube(
        QVector3D(1, 1, 0.2f),
        QVector3D(0.5f, 0.5f, 0),
        NULL
        )
    //targetSuperCluster(0)
{
    cube.hide(true);
    grid.hide(true);
    manager.setActive(false);
    cube.setActive(false);
    cube.getCube()->hide(true);

    cube.setCallback(std::bind(&SuperClusterScene::clicked, this, placeholders::_1, placeholders::_2));
}

SuperClusterScene::~SuperClusterScene()
{
    if (isCurrentScene())
        tearDown();
}


void SuperClusterScene::tearDown()
{
    while (spawned.size() != 0)
    {
        delete spawned[spawned.size()-1];
        spawned.pop_back();
    }
    cube.hide(true);
    grid.hide(true);
    manager.setActive(false);
    cube.setActive(false);
    cube.getCube()->hide(true);
    if (superCluster)
    {
        delete superCluster;
        superCluster = NULL;
    }
}

void SuperClusterScene::setUp()
{
    //GameWall wall;
    //std::cout << "setting up supercluster "<< targetSuperCluster << "\n";
    if (!superCluster)
        superCluster = new SuperCluster(GameData::getData()->getCurrentSuperCluster());
    cube.hide(false);
    grid.hide(false);
    manager.setActive(true);
    grid.setActive(true);
    cube.setActive(true);
    cube.getCube()->hide(false);

    Camera3D* cam(renderer::Device::getGraphicWindow()->getCamera());
    cam->setTranslation(0, 0, 60);
    cam->setRotation(QQuaternion::fromEulerAngles(0,0,0));
}

void SuperClusterScene::update()
{
    Camera3D* camera(renderer::Device::getGraphicWindow()->getCamera());
    if (Input::keyTriggered(Qt::Key_Escape) || camera->translation().z() > 70)
    {
        camera->setTranslation(-1*superCluster->getTransform()->translation().x(),
                               -1*superCluster->getTransform()->translation().y(),
                               camera->translation().z());
        GameScenes::getScenes()->wallScene.setAsCurrent();
    }

}

void SuperClusterScene::clicked(int x, int y)
{
    std::cout << y << ", " << x << "\n";
    std::cout << 50*(y+25) << ", " << x+25 << "\n";
    GameData::getData()->setCurrentCluster(x+25, y+25);
   // return;
    if (GameData::getData()->getCurrentCluster() && GameData::getData()->getCurrentCluster()->getQuads()->size() > 0)
        GameScenes::getScenes()->clusterScene.setAsCurrent();
    else
        std::cout << "not accessed cluster\n";
   // renderer::Device::getGraphicWindow()->getCamera()->setTranslation(0, 0, 60);

}


