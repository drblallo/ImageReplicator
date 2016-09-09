#include "gamewall.h"
#include <iostream>
#include <cmath>

using namespace game;
GameWall::GameWall()
{
    generate(45); //17, 31, 33, 40, 41, 43, 44
}

void GameWall::generate(int seed)
{
    dots.clear();
    //loc.clear();
    float pi(std::acos(-1));
    std::default_random_engine generator;
    generator.seed(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1);

    std::vector<Node> tierOneDots;
    tierOneDots.push_back(Node(distribution(generator)*2*-SIZE, distribution(generator)*-SIZE, 0));
    tierOneDots.push_back(Node(distribution(generator)*2*-SIZE, distribution(generator)*SIZE, 0));
    tierOneDots.push_back(Node(distribution(generator)*2*SIZE, distribution(generator)*-SIZE, 0));
    tierOneDots.push_back(Node(distribution(generator)*2*SIZE, distribution(generator)*SIZE, 0));

    std::vector<Node> outsideDots[4];

    for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < 2; b++)
        {
            float num(distribution(generator)*3);
            for (int c = 0; c < num; c++)
            {
                float x(0);
                if (b == 0)
                    x = -EXT_SIZE -(EXT_SIZE*2*distribution(generator));
                else
                    x = EXT_SIZE + (EXT_SIZE*2*distribution(generator));

                float y(0);
                if (a == 0)
                    y = -EXT_SIZE -(EXT_SIZE*distribution(generator));
                else
                    y = EXT_SIZE + (EXT_SIZE*distribution(generator));

                QVector3D col (distribution(generator)*QVector3D(1, 1, 1));
                outsideDots[(2*b)+a].push_back(Node(QVector3D(x, y, 0), col));
            }
        }
    }

    for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < 2; b++)
        {
            for (unsigned int c = 0; c < outsideDots[(2*b)+a].size(); c++)
            {
                outsideDots[(2*b)+a][c].setAdjactent(&tierOneDots[(2*b)+a]);
            }
        }
    }


    float distorsions[8];
    for (int a = 0; a < 8; a++)
    {
        distorsions[a] = distribution(generator) * 8.0f + 1;
    }

    tierOneDots[0].setAdjactent(&tierOneDots[1]);
    tierOneDots[0].setAdjactent(&tierOneDots[2]);
   // tierOneDots[0].setAdjactent(&tierOneDots[3]);
    tierOneDots[1].setAdjactent(&tierOneDots[3]);
    tierOneDots[2].setAdjactent(&tierOneDots[3]);
    tierOneDots[0].color = QVector3D(0.8, 0.8, 0.8);
    tierOneDots[1].color = QVector3D(0.8, 0.8, 0.8);
    tierOneDots[2].color = QVector3D(0.8, 0.8, 0.8);
    tierOneDots[3].color = QVector3D(0.8, 0.8, 0.8);

    std::vector<Node> tierTwoDows[4];

    for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < 2; b++)
        {
            float quantity((distribution(generator)*10)+6);
            for (int c = 0; c < quantity; c++)
            {
                tierTwoDows[(a*2)+b].push_back(Node(
                                                   (distribution(generator)*(-2*EXT_SIZE))+(2*EXT_SIZE*a),
                                                   (distribution(generator)*(-EXT_SIZE))+(EXT_SIZE*b),
                                                   0)
                                               );
            }
            for (unsigned int c = 0; c < tierTwoDows[(a*2)+b].size(); c++)
            {
                 tierOneDots[(a*2)+b].inferiorNodes.push_back(&(tierTwoDows[(a*2)+b][c]));
                 tierTwoDows[(a*2)+b][c].color = distribution(generator)*QVector3D(1, 1, 1);
            }
        }
    }

    Node* from(NULL);
    Node* to(NULL);
    Node* extra(NULL);
    for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < 2; b++)
        {
            float quantity(distribution(generator)* 7500);
            quantity += 7500;
            for (int c = 0; c < quantity; c++)
            {
                float rand(distribution(generator));
                if (rand < 0.8f)
                {
                    from = &tierOneDots[(a*2)+b];
                    extra = &tierOneDots[(a*2)+b];
                }
                else
                {
                    from = &tierTwoDows[(a*2)+b][tierTwoDows[(a*2)+b].size() * distribution(generator)];
                    extra = &tierOneDots[(a*2)+b];
                }
              //  if (rand > 0.98)
                //    from = NULL;

              //  float rand2(distribution(generator));
               // if (rand2 < 1)
                //{
                    to = (extra->adjactent.at(extra->adjactent.size()*distribution(generator)));
                //}
               // else
                //{
                  //  int f = 4.0f*distribution(generator);
                   // to = &(tierTwoDows[f][tierTwoDows[f].size()*distribution(generator)]);
                //}
                if (extra != from)
                    to = extra;
                //if (rand2 > 0.98)

                  //  to = NULL;

                if (from && to)
                {
                    if (from == to)
                    {
                        //float x(distribution(generator) - 0.5f);
                        //x = x*x;
                        //float y(distribution(generator) - 0.5f);
                        //y = y*y;

                        //dots.push_back(Dot(from->pos+QVector3D(10*x, 10*y, 0), from->color));
                    }
                    else
                    {
                        float pos(distribution(generator));
                        QVector3D p((pos*from->pos)+((1-pos)*to->pos));
                        float posCol(distribution(generator)+ pos);
                        posCol = posCol/2.0f;
                        QVector3D col((posCol*from->color)+((1-posCol)*to->color));
                        //col += QVector3D(distribution(generator), distribution(generator), distribution(generator))/3.0;
                        p += QVector3D(
                            distribution(generator)*((0.5-pos))*distribution(generator) * 5,
                            distribution(generator)*((0.5-pos))*distribution(generator) * 5,
                            0);

                        p +=  QVector3D(
                            std::sin(pos*distorsions[(2*a)+b]*pi),
                            std::cos(pos*distorsions[(2*a)+b+1]*pi), 0);
                        dots.push_back(Dot(p, col));
                    }
                }
                else
                {
                    dots.push_back(Dot((distribution(generator)*-(2*SIZE))+SIZE, (distribution(generator)*-(2*SIZE))+SIZE, 0));
                }
            }
        }
    }

    for (unsigned int a = 0; a < tierOneDots.size(); a++)
    {
        dots.push_back(Dot(tierOneDots[a].pos, tierOneDots[a].color));
   //     Transform3D transform;
    //    transform.setTranslation(tierOneDots[a].pos);
    //    transform.setScale(10 + (distribution(generator)*10));
    //    loc.push_back(FloatingQuad(transform, QVector4D(tierOneDots[a].color, 0.0*distribution(generator))));
    }

  /*  for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < 2; b++)
        {
            for (unsigned int c = 0; c < outsideDots[(2*a)+b].size(); c++)
            {
                Transform3D transform;
                transform.setTranslation(outsideDots[(2*a)+b][c].pos);
                transform.setScale(50 + (distribution(generator)*10));
                loc.push_back(FloatingQuad(transform, QVector4D(outsideDots[(2*a)+b][c].color, 0.0*distribution(generator))));
            }
        }
    }*/
    for (int b = 0; b < 4; b++)
    {
        for (unsigned int a = 0; a < tierTwoDows[b].size(); a++)
        {
            dots.push_back(Dot(tierTwoDows[b][a].pos,tierTwoDows[b][a].color));
            //Transform3D transform;
           // transform.setTranslation(tierTwoDows[b][a].pos);
            //transform.setScale(10 + (distribution(generator)*5));
         //   loc.push_back(FloatingQuad(transform, QVector4D(tierTwoDows[b][a].color, 0.0*distribution(generator))));
        }
    }

    for (unsigned int a = 0; a < dots.size(); a++)
    {
        float target(0);
        if (std::abs(dots[a].pos.x()) >= 50 || std::abs(dots[a].pos.y()) >= 50)
            continue;

        if (dots[a].pos.x() > 0)
            target = 1;
        if (dots[a].pos.y() > 0)
            target += 2;

        superClusters[int(target)].push_back(&(dots[a]));
    }

}
