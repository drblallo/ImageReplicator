#include "cubeobject.h"
#include "render/device.h"
#include "render/glwidget.h"
#include "render/input.h"
#include <cmath>
#include <iostream>
#include "game/gamedata.h"
#include "game/gamesupercluster.h"

using namespace game;

std::vector<Dot> CubeObject::lines;

CubeObject::CubeObject(
        QVector3D size,
        QVector3D pos,
        std::function<void (int,int)> fun
        ) :
    LinesObject(getLines()),
    offsett(pos),
    callBack(fun)
{
    transform.scale(size);
    transform.setTranslation(0, 0, 0);
}

CubeObject::~CubeObject()
{

}

void CubeObject::Update()
{
    QVector3D cam(Device::getGraphicWindow()->getCamera()->translation());
    QVector3D dir(Device::getGraphicWindow()->getMouseForward());



    float t(0);
    if (dir.z() != 0)
        t = -cam.z()/dir.z();

    QVector3D pos(cam+(t*dir));

    //pos -= QVector3D(1, 1, 1);
    int x(std::floor(pos.x()/transform.scale().x()));
    int y(std::floor(pos.y()/transform.scale().y()));
    pos = QVector3D(x*transform.scale().x(), y*transform.scale().y(), 0);
    pos += offsett;
    //pos -= QVector3D(transform.scale().x(), transform.scale().y(), 1);
    if (t==0)
        transform.setTranslation(0, 0, 0);
    else
        transform.setTranslation(pos);

    internal.getTransform()->setTranslation(transform.translation());
    internal.getTransform()->setScale(transform.scale());

    if (Input::buttonTriggered(Qt::LeftButton) && callBack)
    {
        callBack(x, y);
    }

   // if (GameData::getData()->getCurrentSuperCluster())
    //    if (GameData::getData()->getCurrentSuperCluster()->getCluster(x+25, y+25))
    //std::cerr << x+25 << ", " << y+25 << ": " << GameData::getData()->getCurrentSuperCluster()->getCluster(x+25, y+25)->size() << "\n";
}

std::vector<Dot>* CubeObject::getLines()
{
    if (lines.size() == 0)
    {
        QVector3D col(1, 0, 0);

        QVector3D ldf(-0.5, -0.5, -0.5);
        QVector3D rdf(0.5, -0.5, -0.5);
        QVector3D luf(-0.5, 0.5, -0.5);
        QVector3D ruf(0.5, 0.5, -0.5);

        QVector3D ldb(-0.5, -0.5, 0.5);
        QVector3D rdb(0.5, -0.5, 0.5);
        QVector3D lub(-0.5, 0.5, 0.5);
        QVector3D rub(0.5, 0.5, 0.5);

        lines.push_back(Dot(ldf, col));
        lines.push_back(Dot(rdf, col));
        lines.push_back(Dot(ldf, col));
        lines.push_back(Dot(luf, col));
        lines.push_back(Dot(ldf, col));
        lines.push_back(Dot(ldb, col));

        lines.push_back(Dot(ruf, col));
        lines.push_back(Dot(luf, col));
        lines.push_back(Dot(ruf, col));
        lines.push_back(Dot(rdf, col));
        lines.push_back(Dot(ruf, col));
        lines.push_back(Dot(rub, col));

        lines.push_back(Dot(lub, col));
        lines.push_back(Dot(rub, col));
        lines.push_back(Dot(lub, col));
        lines.push_back(Dot(ldb, col));
        lines.push_back(Dot(lub, col));
        lines.push_back(Dot(luf, col));

        lines.push_back(Dot(rdb, col));
        lines.push_back(Dot(ldb, col));
        lines.push_back(Dot(rdb, col));
        lines.push_back(Dot(rub, col));
        lines.push_back(Dot(rdb, col));
        lines.push_back(Dot(rdf, col));
    }
    return &lines;
}
