#include "internalcube.h"

using namespace game;

std::vector<Dot> InternalCube::lines;

InternalCube::InternalCube() : TrisObject(getLines())
{

}

InternalCube::~InternalCube()
{

}

std::vector<Dot>* InternalCube::getLines()
{
    if (lines.size() == 0)
    {
        QVector3D green(0, 0, 0.2f);
        lines.push_back(Dot(QVector3D(0.5, 0.5, 0.5), green));
        lines.push_back(Dot(QVector3D(1, 1, -1)/2, green));
        lines.push_back(Dot(QVector3D(1, -1, 1)/2, green));

        lines.push_back(Dot(QVector3D(1, -1, 1)/2, green));
        lines.push_back(Dot(QVector3D(1, 1, -1)/2, green));
        lines.push_back(Dot(QVector3D(1, -1, -1)/2, green));

        lines.push_back(Dot(QVector3D(-1, 1, 1)/2, green));
        lines.push_back(Dot(QVector3D(-1, -1, 1)/2, green));
        lines.push_back(Dot(QVector3D(-1, 1, -1)/2, green));

        lines.push_back(Dot(QVector3D(-1, -1, 1)/2, green));
        lines.push_back(Dot(QVector3D(-1, -1, -1)/2, green));
        lines.push_back(Dot(QVector3D(-1, 1, -1)/2, green));

//
        lines.push_back(Dot(QVector3D(-1, 1, 1)/2, green));
        lines.push_back(Dot(QVector3D(-1, 1, -1)/2, green));
        lines.push_back(Dot(QVector3D(1, 1, -1)/2, green));

        lines.push_back(Dot(QVector3D(-1, 1, 1)/2, green));
        lines.push_back(Dot(QVector3D(1, 1, -1)/2, green));
        lines.push_back(Dot(QVector3D(1, 1, 1)/2, green));

        lines.push_back(Dot(QVector3D(-1, -1, -1)/2, green));
        lines.push_back(Dot(QVector3D(-1, -1, 1)/2, green));
        lines.push_back(Dot(QVector3D(1, -1, -1)/2, green));

        lines.push_back(Dot(QVector3D(1, -1, -1)/2, green));
        lines.push_back(Dot(QVector3D(-1, -1, 1)/2, green));
        lines.push_back(Dot(QVector3D(1, -1, 1)/2, green));

//
        lines.push_back(Dot(QVector3D(-1, 1, 1)/2, green));
        lines.push_back(Dot(QVector3D(1, 1, 1)/2, green));
        lines.push_back(Dot(QVector3D(1, -1, 1)/2, green));

        lines.push_back(Dot(QVector3D(-1, -1, 1)/2, green));
        lines.push_back(Dot(QVector3D(-1, 1, 1)/2, green));
        lines.push_back(Dot(QVector3D(1, -1, 1)/2, green));

        lines.push_back(Dot(QVector3D(1, 1, -1)/2, green));
        lines.push_back(Dot(QVector3D(-1, 1, -1)/2, green));
        lines.push_back(Dot(QVector3D(1, -1, -1)/2, green));

        lines.push_back(Dot(QVector3D(-1, 1, -1)/2, green));
        lines.push_back(Dot(QVector3D(-1, -1, -1)/2, green));
        lines.push_back(Dot(QVector3D(1, -1, -1)/2, green));
    }
    return &lines;
}
