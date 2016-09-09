#include "galaxygenerator.h"
#include <random>
#include <cmath>
#include <iostream>
#define BASE_INTENSITY 1
#define EXTRA_INTESITY 1
#define BASE_RADIOUS 10
#define EXTRA_RADIOUS 10

using namespace game;

GalaxyGenerator::GalaxyGenerator(int s) : seed(s)
{
    setUp();
}

void GalaxyGenerator::setGeneration(int s)
{
    seed = s;
    setUp();
}

void GalaxyGenerator::setUp()
{
    std::default_random_engine generator;
    tiers.clear();
    generator.seed(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1);

    float numberOfTiers(2+distribution(generator)*2);
    //numberOfTiers = 2;
    float lastRadious(0);
    for (int a = 0; a < numberOfTiers; a++)
    {
        if (a == 0)
            tiers.push_back(GalaxyGenerationData
                    (
                        (BASE_INTENSITY +(EXTRA_INTESITY*distribution(generator))),
                        0,//lastRadious
                        lastRadious + BASE_RADIOUS +(EXTRA_RADIOUS*distribution(generator)),
                        QVector3D(distribution(generator), distribution(generator), distribution(generator)),
                        QVector3D(distribution(generator), distribution(generator), distribution(generator))

                    ));
        else
            if (a == 1)
                tiers.push_back(GalaxyGenerationData
                    (
                    (BASE_INTENSITY +(EXTRA_INTESITY*distribution(generator))),
                    0,//lastRadious
                    lastRadious + BASE_RADIOUS +(EXTRA_RADIOUS*distribution(generator)),
                    tiers[a-1].endColor,
                    QVector3D(distribution(generator), distribution(generator), distribution(generator))

                    ));
            else
                tiers.push_back(GalaxyGenerationData
                    (
                    (BASE_INTENSITY +(EXTRA_INTESITY*distribution(generator))),
                    tiers[a-2].radii,//lastRadious
                    lastRadious + BASE_RADIOUS +(EXTRA_RADIOUS*distribution(generator)) - tiers[a-2].radii,
                    tiers[a-1].endColor,
                    QVector3D(distribution(generator), distribution(generator), distribution(generator))

                    ));

        lastRadious = (tiers[tiers.size()-1]).radii + (tiers[tiers.size()-1]).external;

    }

}

void GalaxyGenerator::populate(std::vector<renderer::Dot> *list, std::vector<renderer::FloatingQuad> *quads) const
{
    list->clear();
    std::default_random_engine generator;
    generator.seed(seed);
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    float vertDistance((dist(generator)*10) + 5);
    for (unsigned int a = 0; a < tiers.size(); a++)
    {
       // tiers[a].populate(list, &generator, &distribution);

        float starQuantity((tiers[a]).getStarQuantity());
        for (int b = 0; b < starQuantity/2; b++)
        {
            float pos((dist(generator)*tiers[a].external)+tiers[a].radii);
            float rot(dist(generator)*2*(std::acos(-1)));
            float col(dist(generator));
            float bulginess(dist(generator)*vertDistance);

            list->push_back(
                        renderer::Dot(
                            QVector3D(pos*std::cos(rot), pos*std::sin(rot), (bulginess)/ (pos+2)),
                            ((col*tiers[a].startColor) + ((1.0-col)*tiers[a].endColor))
                            ));

        }
       // std::cout << "done one\n";
        //for (int b = 0; b < 10; b++)
    }
    for (int a = tiers.size()-1; a >= 0; a--)
   // for (unsigned int a = 0; a < tiers.size(); a++)
    {

        float quant(3.14 * (((tiers[a].radii+tiers[a].external)*(tiers[a].radii+tiers[a].external))-(tiers[a].radii*tiers[a].radii)));
        std::cout << quant << "\n";
        for (int b = 0; b < quant/10; b++)
        {
            float pos((dist(generator)*tiers[a].external)+tiers[a].radii);
            float rot(dist(generator)*2*(std::acos(-1)));
            float col(dist(generator));
            float dim((2*dist(generator))+a+4);
            float dim2((2*dist(generator))+a+4);

            QVector3D spotColor((col * tiers[a].endColor) + ((1-col)*tiers[a].startColor));
            renderer::FloatingQuad quad(QVector4D(spotColor, 0.06f + (0.02f*(tiers.size()-a))));

            quad.transform.setScale(dim, dim2, 1);
            quad.transform.setTranslation(pos*std::cos(rot), pos*std::sin(rot), 0);
             //   quad.transform.setTranslation(0, 0, (a));

            quads->push_back(quad);

        }

    }
}


