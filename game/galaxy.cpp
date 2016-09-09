#include "galaxy.h"
#include <cmath>
#include <cstdlib>
#include <QOpenGLShaderProgram>
#include <iostream>
#include "galaxygenerator.h"
#include "render/device.h"
#include <QOpenGLTexture>

using namespace game;


Galaxy::Galaxy(std::vector<Dot>* stars, std::vector<FloatingQuad> *quads) : DottedObject(stars), floor(quads)//(&vertString, &fragString)
{

}

Galaxy::~Galaxy()
{

}
