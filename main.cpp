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
#include "globalsettings.h"
#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
	GlobalSettings* settings(GlobalSettings::getSettings());
	QString imageName(QString::fromStdString(settings->file_name));
    QImage original(imageName);
    //QImage sobelImage(roberts(original));
    QImage sobelImage(sobel(original));
    //QImage sobelImage(scharr(original));
    //QImage sobelImage(canny(original, 0.5f,0.5f, 0.5f));

    std::vector<float> ls;
    generateLines(&ls, &original, &sobelImage);

    mechanics::MechanicsEngine::StartEngine();

    QApplication a(argc, argv);
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(4,1);
    format.setDepthBufferSize(a.desktop()->depth());
    format.setSamples(2);
    format.setOption(QSurfaceFormat::DebugContext);
    format.setSwapInterval(-1);
    QSurfaceFormat::setDefaultFormat(format);

    MainWindow w;
    w.resize(a.desktop()->size().width(), a.desktop()->size().height());
	QVector4D v(settings->red_clear, settings->green_clear, settings->blue_clear, settings->alpha_clear);
    w.show();
	w.getUI()->openGLWidget->setClearColor(v);

    ImageReplicatorScene scene(&original, &sobelImage, &ls);
    return a.exec();
}
