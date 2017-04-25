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
#include "appearinglines.h"
#include "render/defaultscene.h"
#include <random>
#include <algorithm>
#include "globaldefines.h"
#include "utils.h"
#include "imagereplicatorscene.h"


int main(int argc, char *argv[])
{
    QImage original(QString("image.jpg"));
    //QImage sobelImage(roberts(original));
    QImage sobelImage(sobel(original));
    //QImage sobelImage(canny(original, 0.5f,0.5f, 0.5f));

    std::vector<renderer::Dot> ls;
    generateLines(&ls, &original, &sobelImage);

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
    w.resize(a.desktop()->size().width(), a.desktop()->size().height());
    w.show();

    ImageReplicatorScene scene(&original, &sobelImage, &ls);
    return a.exec();
}
