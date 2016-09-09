#include "grid.h"
#include "render/device.h"
#include "render/glwidget.h"

using namespace game;

std::vector<Dot> Grid::lines;

Grid::Grid() : LinesObject(getLines(30)), EngineObject(), n(30)
{

    transform.setTranslation(0, 0, 0);
}
Grid::Grid(int num) : LinesObject(getLines(num)), EngineObject(), n(num)
{

    transform.setTranslation(0, 0, 0);
}

Grid::~Grid()
{

}

void Grid::Update()
{//	QVector3D v(Device::getGraphicWindow()->getCamera()->translation());
   // transform.setTranslation(int(v.x()), int(v.y()), 0);
}

std::vector<Dot>* Grid::getLines(int t)
{
    if (lines.size() == 0)
    {
        QVector3D green(0, 0, 0.2f);
        for (int a = -t; a <= t; a++)
        {
            lines.push_back(Dot(QVector3D(a, -t, 0), green));
            lines.push_back(Dot(QVector3D(a, t, 0), green));
        }
        for (int a = -t; a <= t; a++)
        {
            lines.push_back(Dot(QVector3D(-t, a, 0), green));
            lines.push_back(Dot(QVector3D(t, a, 0), green));
        }
    }
    return &lines;
}
