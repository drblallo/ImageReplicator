#pragma once
#include "render/textureswarmobject.h"
#include <QVector3D>
#include <vector>

using namespace renderer;
namespace game
{
    class GalaxyFloor : public /*TexturedObject*/ TextureSwarmObject
    {
        public:
            GalaxyFloor(std::vector<FloatingQuad>* quads);
            virtual ~GalaxyFloor();
            static std::string nebulaString;
            static QOpenGLTexture* getNebulaTexture();
        protected:
            static QOpenGLTexture* nebulaTexture;

    };
}
