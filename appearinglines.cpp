#include "appearinglines.h"
#include "render/input.h"
#include "globalsettings.h"
#include "render/device.h"
#include <string>
#include <QOpenGLShaderProgram>
#include <iostream>

QOpenGLShaderProgram* s(NULL);
int AppearingLines::structSize(7);

void randomize(std::vector<float>* vec)
{
	int sSize(AppearingLines::structSize);
    int vCount(vec->size() / (sSize*2));

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, vCount);
    renderer::Dot d(QVector3D(0,0,0), QVector3D(0,0,0));

    int target(0);
    for (int a = 0; a < vCount; a++)
    {
        target = distribution(generator);
        for (int v = 0; v < (sSize-1); v++)
            std::swap((*vec)[target * (sSize*2) + v], (*vec)[a * (sSize*2) + v]);

        for (int v = sSize; v < (sSize*2)-1; v++)
            std::swap((*vec)[target * (sSize*2) + v], (*vec)[a * (sSize*2) + v]);
    }
}

void generateLines(std::vector<float>* ls, QImage* original, QImage* sobelImage)
{
	GlobalSettings* settings(GlobalSettings::getSettings());
	int treshHold(settings->treshHold);
	int scale(settings->scala);
	int dropped(settings->dropped);
	float depth(settings->depth);
	int sSize(AppearingLines::structSize);

    std::default_random_engine generator;
    std::uniform_real_distribution<float> distributionReal(0, 1);

    for (int a = 1; a < sobelImage->height()-1; a++)
    {
        QRgb* line((QRgb*)(sobelImage->scanLine(a)));
        QRgb* lc((QRgb*)(original->scanLine(a)));

        for (int b = 1; b < sobelImage->width()-1; b++)
        {
            QColor col(qRed(line[b]), qGreen(line[b]), qBlue(line[b]));
            QColor originCol(qRed(lc[b]), qGreen(lc[b]), qBlue(lc[b]));

            if (col.red() > treshHold || col.green() > treshHold || col.blue() > treshHold)
            {
                QVector3D v(float(originCol.red())/255.0f, float(originCol.green())/255.0f, float(originCol.blue())/255.0f);
                ls->push_back(1*b + (scale * distributionReal(generator)));
                ls->push_back(-1*a + (scale * distributionReal(generator)));
                ls->push_back(-10.0f - ((distributionReal(generator)) * depth));
                ls->push_back(v.x());
                ls->push_back(v.y());
                ls->push_back(v.z());
                ls->push_back(0);


                ls->push_back(1*b);
                ls->push_back(-1*a);
                ls->push_back(-10);
                ls->push_back(v.x());
                ls->push_back(v.y());
                ls->push_back(v.z());
                ls->push_back((ls->size() - (2 * sSize) + 1) / sSize);
            }
        }
    }

    randomize(ls);

    int t(ls->size() / dropped);
    while (t % sSize != 0)
        t--;
    ls->erase(ls->begin()+t, ls->end());

}

QOpenGLShaderProgram* getProgram()
{
    if (!s)
    {
		std::cerr << "trying to create a shader" << std::endl;
        std::string vertexShader(":/shaders/appearinglines.vert");
        std::string fragShader(":/shaders/simple.frag");
        s = renderer::Device::createProgram(&vertexShader, &fragShader);
    }

    if (!s)
        std::cerr << "failed to load shader" << std::endl;

    return s;
}

AppearingLines::AppearingLines(std::vector<float> *d) :
   	LinesObject(getProgram()),
   	EngineObject()
{
    trueVCount = d->size() / structSize;

    d->push_back(d->at(d->size() - 3));
    d->push_back(d->at(d->size() - 3));
    d->push_back(d->at(d->size() - 3));
    std::cerr << d->size() << std::endl;
    setBuffer(&(d->at(0)), d->size() * sizeof(float));

    vCount = 0;
    timeElapsed = 0;

    if (!shader)
        std::cerr << "no shader" << std::endl;
    shader->bind();
    shaderTime = shader->uniformLocation("timeLeft");
    vertexCount = shader->uniformLocation("vertexCount");
    shader->release();

    renderState.blending.setEnabled(true);
    renderState.blending.setDestinationAlphaFactor(DestinationBlendingOneMinusAlpha);
    renderState.blending.setSourceAlphaFactor(SourceBlendingSourceAlpha);
    renderState.depthMask = false;
}

AppearingLines::AppearingLines(QImage* image, QImage* original) :
   	LinesObject(getProgram()),
   	EngineObject()
{
	std::vector<float> d;
	if (GlobalSettings::getSettings()->black_and_white != 1)
		generateLines(&d, original, image);
	else
		generateLines(&d, image, image);
    trueVCount = d.size() / structSize;

    d.push_back(d.at(d.size() - 3));
    d.push_back(d.at(d.size() - 3));
    d.push_back(d.at(d.size() - 3));
    std::cerr << d.size() << std::endl;
    setBuffer(&(d.at(0)), d.size() * sizeof(float));

    vCount = 0;
    timeElapsed = 0;

    if (!shader)
        std::cerr << "no shader" << std::endl;
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
        timeElapsed = trueVCount * 100;
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
    std::cerr << "called" << std::endl;
    shader->bind();
    buffer.bind();
    AO.bind();

    buffer.allocate(pos, size);
    shader->enableAttributeArray(0);
    shader->enableAttributeArray(1);
    shader->enableAttributeArray(2);
    shader->enableAttributeArray(3);

	int floatSize(sizeof(float));

    shader->setAttributeBuffer(0, GL_FLOAT, 0, 3, structSize * floatSize);
    shader->setAttributeBuffer(1, GL_FLOAT, 3 * floatSize, 3, structSize * floatSize);
    shader->setAttributeBuffer(2, GL_FLOAT, 6 * floatSize, 1, structSize * floatSize);
    shader->setAttributeBuffer(3, GL_FLOAT, structSize * floatSize, 3, structSize * floatSize);

    AO.release();
    buffer.release();
    shader->release();
    std::cerr << "done" << std::endl;
}
