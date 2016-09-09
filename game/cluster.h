#pragma once
#include "render/textureswarmobject.h"
#include <QVector3D>
#include <vector>
#include "utils/connectlines.h"

using namespace renderer;
namespace game
{
    class GameCluster;
    class Cluster : public  TextureSwarmObject
    {
        public:
            Cluster(GameCluster* c);//std::vector<FloatingQuad>* quads);
            virtual ~Cluster();
            static std::string nebulaString;
            static QOpenGLTexture* getNebulaTexture();
        protected:
            static QOpenGLTexture* nebulaTexture;
            ConnectLines* lines;

    };
}
