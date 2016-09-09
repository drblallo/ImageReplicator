#pragma once
#include "render/dottedobject.h"
#include <string>
#include <vector>
#include <QVector3D>
#include "galaxyfloor.h"
#define STAR_SLOTS 100

class QOpenGLTexture;
using namespace renderer;
namespace game
{
    class Wall : public DottedObject
    {
        public:
            Wall(const std::vector<Dot>* stars);
            virtual ~Wall();
        private:
           // GalaxyFloor floor;
    };
}
