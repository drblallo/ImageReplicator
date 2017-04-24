#include "mainwindow.h"
#include <QApplication>
#include <QSurfaceFormat>
#include <QDesktopWidget>
#include "mechanics/mechanicsengine.h"
#include <QStyleFactory>
#include "iostream"
#include "edgeDetection/algorithms.h"
#include <functional>
#include <QImage>
#include "render/dottedobject.h"
#include "appearinglines.h"
#include "render/defaultinputmanager.h"
#include "render/defaultscene.h"
#include <random>
#include <algorithm>

#define TRESH 20
#define SCALA 7
#define DROPPED 4

std::default_random_engine generator;
std::uniform_real_distribution<float> distributionReal(0, 1);

void randomize(std::vector<renderer::Dot>* vec)
{
    int vCount = vec->size()/2;

    std::uniform_int_distribution<int> distribution(0, vCount);
    renderer::Dot d(QVector3D(0,0,0), QVector3D(0,0,0));

    for (int a = 0; a < vCount; a++)
    {
        int target(distribution(generator));
        d = (*vec)[target*2];
        (*vec)[target*2] = (*vec)[a*2];
        (*vec)[a*2] = d;

        d = (*vec)[target*2+1];
        (*vec)[target*2+1] = (*vec)[a*2+1];
        (*vec)[a*2+1] = d;
    }
}


int main(int argc, char *argv[])
{
    std::cerr << "started\n";
    QImage sobelImage(roberts(QImage(QString("image.jpg"))));
    std::vector<renderer::Dot> ls;
    for (int a = 0; a < sobelImage.height(); a++)
    {
        QRgb* line((QRgb*)(sobelImage.scanLine(a)));

        for (int b = 0; b < sobelImage.width(); b++)
        {
            QColor col(qRed(line[b]), qGreen(line[b]), qBlue(line[b]));
            if (col.red() > TRESH || col.green() > TRESH || col.blue() > TRESH)
            {
                ls.push_back(renderer::Dot(
                                 QVector3D(1*b, -1*a, -10),
                                 QVector3D(col.red(), col.green(), col.blue())
                                 )
                             );

                ls.push_back(renderer::Dot(
                                 QVector3D(1*b + (SCALA*distributionReal(generator)), -1*a + (SCALA*distributionReal(generator)), -10),
                                 QVector3D(col.red(), col.green(), col.blue())
                                 )
                             );
            }
        }
    }

    randomize(&ls);

    ls.erase(ls.begin()+ls.size()/DROPPED, ls.end());

    std::cerr << "created\n";

    mechanics::MechanicsEngine::StartEngine();

    QApplication a(argc, argv);
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(3,3);
    format.setDepthBufferSize(a.desktop()->depth());
    format.setSamples(2);
    format.setOption(QSurfaceFormat::DebugContext);
    format.setSwapInterval(-1);

    QSurfaceFormat::setDefaultFormat(format);


    MainWindow w;
    w.resize(1366, 768);
    w.show();

    renderer::DefaultScene scene;
    renderer::DefaultInputManager man;

    AppearingLines ogg(&ls);

    float divisor(0);

    if (w.width() > w.height())
        divisor = w.width();
    else
        divisor = w.height();

    divisor = 10/divisor;

    ogg.getTransform()->setScale(divisor, divisor, 1);
    ogg.getTransform()->setTranslation(QVector3D(
                                           float(ogg.getTransform()->scale().x())/-2.0f*sobelImage.width(),
                                           float(ogg.getTransform()->scale().y())/2.0f*sobelImage.height(),
                                           0)
                                       );

    return a.exec();
}
