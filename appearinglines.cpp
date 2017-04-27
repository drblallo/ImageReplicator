#include "appearinglines.h"
#include "render/input.h"
#include "globaldefines.h"
#include "globalsettings.h"
#include "render/device.h"
#include <string>
#include <QOpenGLShaderProgram>
#include <iostream>

QOpenGLShaderProgram* s(NULL);

QOpenGLShaderProgram* getProgram()
{
    if (!s)
    {
        std::cerr << "trying to create a shader\n";
        std::string vertexShader(":/shaders/appearinglines.vert");
        std::string fragShader(":/shaders/simple.frag");
        s = renderer::Device::createProgram(&vertexShader, &fragShader);

    }
    if (!s)
        std::cerr << "failed to load shader\n";
    return s;
}

AppearingLines::AppearingLines(std::vector<float> *d) : LinesObject(getProgram()), EngineObject()
{
    d->push_back(0);
    d->push_back(0);
    d->push_back(0);
    std::cerr << d->size() << "\n";
    setDots(d, (d->size()-3)/7);

    trueVCount = getVertexCount();
    vCount = 0;
    timeElapsed = 0;

    if (!shader)
        std::cerr << "no shader\n";
    shader->bind();
    shaderTime = shader->uniformLocation("timeLeft");
    vertexCount = shader->uniformLocation("vertexCount");
    shader->release();

    renderState.blending.setEnabled(true);
    renderState.blending.setDestinationAlphaFactor(DestinationBlendingOneMinusAlpha);
    renderState.blending.setSourceAlphaFactor(SourceBlendingSourceAlpha);
    renderState.depthMask = false;

}

void AppearingLines::Update()
{
	int divisor(GlobalSettings::getSettings()->generatorion_divisor);
    vCount = vCount + (trueVCount/divisor);
    timeElapsed  += (trueVCount/divisor);
    if (vCount > trueVCount)
    {
        vCount = trueVCount;
    }
    if (Input::keyPressed(Qt::Key_0))
    {
        vCount = 0;
        timeElapsed = 0;
    }
    if (Input::keyPressed(Qt::Key_1))
    {
        vCount = trueVCount;
        timeElapsed = trueVCount*100;
    }
   // std::cerr << timeElapsed << "/"  << trueVCount << "\n";
}

void AppearingLines::Prerender()
{
    LinesObject::Prerender();
    shader->setUniformValue(shaderTime, float(timeElapsed));
    shader->setUniformValue(vertexCount, float(trueVCount));

}

void AppearingLines::setBuffer(const void * pos, int size)
{
    std::cerr << "called\n";
    shader->bind();
    buffer.bind();
    AO.bind();

    buffer.allocate(pos, size);
    shader->enableAttributeArray(0);
    shader->enableAttributeArray(1);
    shader->enableAttributeArray(2);
    shader->enableAttributeArray(3);

    shader->setAttributeBuffer(0, GL_FLOAT, 0, 3, 7*int(sizeof(float)));
    shader->setAttributeBuffer(1, GL_FLOAT, 3*int(sizeof(float)), 3, 7*int(sizeof(float)));
    shader->setAttributeBuffer(2, GL_FLOAT, 6*(int(sizeof(float))), 1, 7*int(sizeof(float)));
    shader->setAttributeBuffer(3, GL_FLOAT, 7*(int(sizeof(float))), 3, 7*int(sizeof(float)));
    std::cerr << "UNDEFINED BEHAVIOUR\n";

    AO.release();
    buffer.release();
    shader->release();
    std::cerr << "done\n";
}
