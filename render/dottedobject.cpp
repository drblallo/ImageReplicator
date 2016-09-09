#include "dottedobject.h"
#include <iostream>
#include "device.h"

using namespace renderer;
std::string DottedObject::vertString(":/shaders/simple.vert");
std::string DottedObject::fragString(":/shaders/simple.frag");
QOpenGLShaderProgram* DottedObject::shader(NULL);

//########################################
//##### Constructors and Conversions #####
//########################################
DottedObject::DottedObject(const std::vector<Dot> *dots) : RenderObject(getShader())
{
    if (!dots)
    {
        std::cout << "no points to spawn\n";
        return;
    }
    if (dots->size() > 0)
        setDots(dots);
    canBeDrawn = true;
}

DottedObject::~DottedObject()
{

}

//########################################
//#####           Methods            #####
//########################################
void DottedObject::setDots(const std::vector<Dot> *dots)
{
    std::cout << "setting up a dotted object of " << dots->size() << "\n";
    RenderObject::setBuffer(&(dots->at(0)), dots->size() * sizeof(Dot));
    vCount = dots->size();
    //std::cout << dots->size() << "\n";
}

GLenum DottedObject::getRenderMode() const
{
    return GL_POINTS;
}

QOpenGLShaderProgram* DottedObject::getShader()
{
    if (!shader)
    {
        shader = Device::createProgram(&vertString, &fragString);
    }
    return shader;
}
