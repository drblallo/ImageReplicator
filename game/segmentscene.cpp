#include "segmentscene.h"
#include "gamesegment.h"
#include "segment.h"
#include <functional>
#include <iostream>
#include "gamescenes.h"
#include "gamedata.h"
#include "render/input.h"
#include "render/device.h"
#include "render/glwidget.h"
#include "gamecluster.h"

using namespace game;
SegmentScene::SegmentScene() :
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

    cube.setCallback(std::bind(&SegmentScene::clicked, this, placeholders::_1, placeholders::_2));
}

SegmentScene::~SegmentScene()
{
    if (isCurrentScene())
        tearDown();
}


void SegmentScene::tearDown()
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

void SegmentScene::setUp()
{
    //GameWall wall;
    //std::cout << "setting up supercluster "<< targetSuperCluster << "\n";
    if (!superCluster && GameData::getData()->getCurrentSegment()->getDots()->size() > 0)
        superCluster = new Segment(GameData::getData()->getCurrentSegment());
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

void SegmentScene::update()
{
    Camera3D* camera(renderer::Device::getGraphicWindow()->getCamera());
    if (Input::keyTriggered(Qt::Key_Escape) || camera->translation().z() > 70)
    {
        if (superCluster)
            camera->setTranslation(-1*superCluster->getTransform()->translation().x(),
                           -1*superCluster->getTransform()->translation().y(),
                           camera->translation().z());
        GameScenes::getScenes()->wallScene.setAsCurrent();
    }

}

void SegmentScene::clicked(int , int )
{

}

