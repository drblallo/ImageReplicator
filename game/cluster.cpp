#include "cluster.h"
#include "render/device.h"
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include <iostream>
#include "gamecluster.h"

using namespace game;

std::string Cluster::nebulaString(":/texture/nebula.png");
QOpenGLTexture* Cluster::nebulaTexture(NULL);

QOpenGLTexture* Cluster::getNebulaTexture()
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



Cluster::Cluster(GameCluster* c /* std::vector<FloatingQuad>* quads*/) : TextureSwarmObject(c->getQuads(), getNebulaTexture())
{
    std::cerr << c->getQuads()->size() << " stars in this\n";
    transform.setTranslation(-25, -25, 0);
    transform.setScale(1, 1, 1);

    std::vector<Dot> ls;
    for (unsigned int a = 0; a < c->getQuads()->size(); a++)
    {
        QVector3D p(c->getQuads()->at(a).transform.translation() - QVector3D(25, 25, 0));
        ls.push_back(Dot(p, QVector3D(0, 0, 0)));
        ls.push_back(Dot(QVector3D(p.x(), p.y(),0 ), QVector3D(1, 0, 0)));
    }

    lines = new ConnectLines(&ls);
}

Cluster::~Cluster()
{
    delete lines;
}
