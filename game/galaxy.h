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
    class Galaxy : public DottedObject
    {
        public:
            Galaxy(std::vector<Dot>* stars, std::vector<FloatingQuad>* quads);
            virtual ~Galaxy();
        protected:
            GalaxyFloor floor;
    };
}
