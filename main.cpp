#include "mainwindow.h"
#include <QApplication>
#include <QSurfaceFormat>
#include <QDesktopWidget>
#include "mechanics/mechanicsengine.h"
#include <QStyleFactory>
#include "iostream"

int main(int argc, char *argv[])
{
//    QApplication::setStyle(QStyleFactory::create("Windows"));
  //  for (unsigned int a = 0; a < QStyleFactory::keys().size(); a++)
    //{
      //  std::cout << QStyleFactory::keys().at(a).toLocal8Bit().constData()<< "\n";
    //}
    mechanics::MechanicsEngine::StartEngine();
//    GameModule m;

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


  //  GameScenes::getScenes()->wallScene.setAsCurrent();

    return a.exec();
}
