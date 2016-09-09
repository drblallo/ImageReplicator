#include "galaxyscene.h"
#include "galaxy.h"
#include "render/defaultinputmanager.h"
#include "render/test/testQuad.h"
#include "galaxygenerator.h"
#include "gamedata.h"
#include "gamegalaxy.h"
#include "render/device.h"
#include "render/glwidget.h"
#include "render/input.h"
#include "gamescenes.h"

using namespace game;
using namespace renderer;
GalaxyScene::GalaxyScene() :
    Scene(),
    grid(GALAXY_SLOT_SIZE/2),
    cube(
        QVector3D(10, 10, 1),
        QVector3D(5, 5, 0),
        NULL
        )
{
   // manager.setActive(false);
    grid.hide(true);
    grid.getTransform()->setScale(10, 10, 10);
    cube.hide(true);
    cube.setActive(false);
    cube.getCube()->hide(true);

    cube.setCallback(std::bind(&GalaxyScene::clicked, this, placeholders::_1, placeholders::_2));
}


GalaxyScene::~GalaxyScene()
{
    if (isCurrentScene())
        tearDown();
}

//########################################
//#####           Methods            #####
//########################################
void GalaxyScene::setUp()
{

    Galaxy* test =  new Galaxy(GameData::getData()->getCurrentGalaxy()->getDots(), GameData::getData()->getCurrentGalaxy()->getQuads());
    spawned.push_back(test);

    //manager.setActive(true);

    Device::getGraphicWindow()->getCamera()->setTranslation(0, -75, 75);
    Device::getGraphicWindow()->getCamera()->setRotation(QQuaternion::fromEulerAngles(40, 0, 0));
    grid.hide(false);

    cube.hide(false);
    cube.setActive(true);
    cube.getCube()->hide(false);
}


void GalaxyScene::tearDown()
{
    while (spawned.size() != 0)
    {
        delete spawned[spawned.size()-1];
        spawned.pop_back();
    }
    //manager.setActive(false);
    grid.hide(true);
    cube.hide(true);
    cube.setActive(false);
    cube.getCube()->hide(true);
}

void GalaxyScene::update()
{
    if (Input::keyTriggered(Qt::Key_Escape))
    {
        GameScenes::getScenes()->clusterScene.setAsCurrent();
    }
}

void GalaxyScene::clicked(int x, int y)
{
    if (!GameData::getData()->getCurrentGalaxy()->getDotSlot(x+25, y+25))
        return;
    if (GameData::getData()->getCurrentGalaxy()->getDotSlot(x+25, y+25)->size() == 0)
        return;
    GameData::getData()->setCurrentSegment(x+25, y+25);
    if (!GameData::getData()->getCurrentSegment())
        return;
    GameScenes::getScenes()->segmentScene.setAsCurrent();


}
