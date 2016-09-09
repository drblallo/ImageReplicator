#pragma once
#include "vector"
#include <QVector3D>
#include "render/dottedobject.h"
#include "render/textureswarmobject.h"

namespace game
{
    struct GalaxyGenerationData
    {
        public:
            GalaxyGenerationData(double intensity, double rad, double exp, QVector3D startC,QVector3D endC) :
                centerIntensity(intensity),
                radii(rad),
                external(exp),
                startColor(startC),
                endColor(endC)
            {

            }

            double centerIntensity;
            double radii;
            double external;
            float distance;
            QVector3D startColor;
            QVector3D endColor;

        //    void populate(vector<QVector3D>* ls, std::uniform_real_distribution *dist) const;
            inline float getStarQuantity() const
            {
                return 3.14 * (((radii+external)*(radii+external))-(radii*radii)) * centerIntensity;
            }
    };

    struct GalaxyGenerationStar
    {
        QVector3D pos;
        QVector3D col;
    };

    class GalaxyGenerator
    {
        public:
            GalaxyGenerator(int s);
            void setGeneration(int seed);
            void populate(std::vector<renderer::Dot>* list, std::vector<renderer::FloatingQuad>*) const;
            inline GalaxyGenerationData* getGenData(int target)
            {
                if (target < 0 || target >= tiers.size())
                    return NULL;
                return &tiers[target];
            }

            inline QVector3D getColor() const
            {
                return tiers[tiers.size()-1].endColor;

            }

        private:
            std::vector<GalaxyGenerationData> tiers;
            int seed;
            void setUp();



    };
}
