#include "galaxyfloor.h"
#include "render/device.h"
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include <iostream>

using namespace game;
//std::string GalaxyFloor::vertString(":/shaders/simpleTex.vert");
//std::string GalaxyFloor::fragString(":/shaders/simpleTex.frag");
std::string GalaxyFloor::nebulaString(":/texture/nebula.png");
QOpenGLTexture* GalaxyFloor::nebulaTexture(NULL);

QOpenGLTexture* GalaxyFloor::getNebulaTexture()
{

    if (!nebulaTexture)
    {
        nebulaTexture = Device::createTexture(&nebulaString);
        nebulaTexture->generateMipMaps();
        nebulaTexture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        nebulaTexture->setMagnificationFilter(QOpenGLTexture::Linear);
        //nebulaTexture->setMagnificationFilter();
    }
    return nebulaTexture;
}



GalaxyFloor::GalaxyFloor(std::vector<FloatingQuad>* quads) : TextureSwarmObject(quads, getNebulaTexture())
{
    transform.setTranslation(0.0f, 0.0f, -5.2f);
    transform.setScale(1, 1, 1);
}

GalaxyFloor::~GalaxyFloor()
{
}
