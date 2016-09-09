#include "gamesegment.h"
#include "gamegalaxy.h"
#include "gamedata.h"
#include <iostream>
#include <cmath>

using namespace game;

GameSegment::GameSegment(int x, int y) : xAdress(x), yAdress(y)
{
    GameGalaxy* gal(GameData::getData()->getCurrentGalaxy());

    if (!gal)
        return;

    if (x < 0 || y < 0)
        return;
    if (x >= GALAXY_SLOT_SIZE || y >= GALAXY_SLOT_SIZE)
        return;


    vector<Dot> points;
    vector<Dot>* zones[3][3];
    for (int a = -1; a < 2; a++)
        for (int b = -1; b < 2; b++)
            zones[a+1][b+1] = gal->getDotSlot(x+a, y+b);

    default_random_engine generator;
    default_random_engine generator2;
    uniform_real_distribution<double> distribution(0.0, 1);

    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            generator.seed((x+a)*gal->getSeed());
            generator2.seed((y+b)*gal->getSeed());
            for (unsigned int c = 0; c < zones[a][b]->size(); c++)
            {
                bool found(false);
                Dot d(zones[a][b]->at(c));
                Dot t(getCorrenspondant(zones, distribution, a, b, generator, generator2, &found));

                if (found)
                {
                    d.pos = d.pos + QVector3D(a-1, b-1, 0);
                    points.push_back(d);
                    points.push_back(t);
                }
                generator.discard(2);
                generator2.discard(1);
            }
        }
    }
    float pi(acos(-1));
    generator.seed(x*gal->getSeed());
    generator2.seed(y*gal->getSeed());
    for (unsigned int a = 0; a < points.size(); a = a+2)
    {
        float quantity(points[a].pos.distanceToPoint(points[a+1].pos));
        quantity = quantity*100;

        for (int b = 0; b < quantity; b++)
        {
            float t(distribution(generator));
            float tCol(distribution(generator));

            QVector3D pos((t*points[a].pos)+((1-t)*points[a+1].pos));
            QVector3D col((tCol*points[a].col)+((1-tCol)*points[a+1].pos));

            pos += QVector3D(cos(gal->getSeed()%10*t*pi), sin((gal->getSeed()%10)*t*pi), 0);
            pos = pos + (0.01f*QVector3D(distribution(generator), distribution(generator), distribution(generator)));

            if (pos.x() > 0 && pos.y() > 0 && pos.x() < 1 && pos.y() < 1)
            {
                pos = pos*50 - QVector3D(25, 25, 0);
                dots.push_back(Dot(pos, col));
            }
        }

    }

    vector<FloatingQuad>* q(gal->getQuadSlot(x, y));
    for (unsigned int a = 0; a < q->size(); a++)
    {
        Transform3D f(q->at(a).transform);
        f.setScale(f.scale()*50);
        f.setTranslation(distribution(generator)*50 -25, distribution(generator)*50 -25, distribution(generator)*50 - 25);
        f.translate(0, 0, f.translation().z()*-1);
        QVector4D col(q->at(a).color[0]);
        col.setW(0.3f);
        quads.push_back(FloatingQuad(f, col));
    }
}

Dot GameSegment::getCorrenspondant
                (
                    vector<Dot>* zones[3][3],
                    uniform_real_distribution<double> distribution,
                    int a,
                    int b,
                    default_random_engine generator,
                    default_random_engine generator2,
                    bool* found
                )
{
    int x(floor((distribution(generator)*3)-1));
    int y(floor((distribution(generator2)*3)-1));

    if (a+x < 0 || a+x > 2 || y+b < 0 || y+b > 2)
    {
        *found = false;
        return Dot(0, 0, 0);
    }

    if (zones[x+a][y+b]->size() == 0)
    {
        *found = false;
        return Dot(0, 0, 0);
    }

    *found = true;

    int target(zones[x+a][y+b]->size()*distribution(generator));
    Dot d(zones[x+a][y+b]->at(target));
    d.pos = d.pos + QVector3D(x+a, y+b, 0);
    return d;
}
