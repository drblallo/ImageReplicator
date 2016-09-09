#include "wallscene.h"
#include <functional>
#include <iostream>
#include "gamescenes.h"
#include "gamedata.h"
#include "render/device.h"
#include "render/glwidget.h"

using namespace game;
using namespace renderer;
WallScene::WallScene() : Scene(),  cube(QVector3D(50, 50, 6),QVector3D(25, 25, 0), NULL)
{
    manager.setActive(false);
    cube.setActive(false);
    cube.hide(true);
    cube.getCube()->hide(true);
    grid.setActive(false);
    grid.hide(true);
    cube.setCallback(std::bind(&WallScene::clicked, this, placeholders::_1, placeholders::_2));
    grid.getTransform()->setScale(10);
}


WallScene::~WallScene()
{
    if (isCurrentScene())
        tearDown();
}

//########################################
//#####           Methods            #####
//########################################
void WallScene::setUp()
{

    Wall* w = new Wall(GameData::getData()->getWall()->getDots());
    spawned.push_back(w);

    cube.setActive(true);
    cube.hide(false);
    manager.setActive(true);
    cube.getCube()->hide(false);
    grid.setActive(true);
    grid.hide(false);
    renderer::Device::getGraphicWindow()->getCamera()->setTranslation(0, 0, 70);
    renderer::Device::getGraphicWindow()->getCamera()->setRotation(QQuaternion::fromEulerAngles(0, 0, 0));

}


void WallScene::tearDown()
{
    while (spawned.size() != 0)
    {
        delete spawned[spawned.size()-1];

        spawned.pop_back();
    }

    manager.setActive(false);
    cube.setActive(false);
    cube.hide(true);
    cube.getCube()->hide(true);
    grid.setActive(false);
    grid.hide(true);
}

void WallScene::clicked(int x, int y)
{
    std::cout << x << ", " << y << "\n";
   // return;
    GameData::getData()->setSuperCluster((2*(y+1))+x+1);
    GameScenes::getScenes()->superClusterScene.setAsCurrent();

}
