#-------------------------------------------------
#
# Project created by QtCreator 2016-08-20T12:53:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = meltingSuns
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        mechanics/characteristic.cpp \
        mechanics/rawbonus.cpp \
        render/glwidget.cpp \
        mechanics/entity.cpp \
        game/visibleentity.cpp \
    render/renderobject.cpp \
    render/transform3d.cpp \
    render/device.cpp \
    render/test/testquad.cpp \
    render/input.cpp \
    render/camera3d.cpp \
    render/engineobject.cpp \
    render/defaultinputmanager.cpp \
    render/scene.cpp \
    render/defaultscene.cpp \
    game/galaxy.cpp \
    game/galaxyscene.cpp \
    game/galaxygenerator.cpp \
    render/texturedobject.cpp \
    game/galaxyfloor.cpp \
    render/dottedobject.cpp \
    render/textureswarmobject.cpp \
    game/gamewall.cpp \
    game/wall.cpp \
    game/wallscene.cpp \
    game/gamesupercluster.cpp \
    game/supercluster.cpp \
    game/superclusterscene.cpp \
    game/utils/cubeobject.cpp \
    render/linesobject.cpp \
    game/utils/grid.cpp \
    render/trisobject.cpp \
    game/utils/internalcube.cpp \
    game/gamescenes.cpp \
    game/gamedata.cpp \
    game/gamecluster.cpp \
    game/cluster.cpp \
    game/clusterscene.cpp \
    game/utils/connectlines.cpp \
    game/gamegalaxy.cpp \
    game/gamesegment.cpp \
    game/segment.cpp \
    game/segmentscene.cpp \
    mechanics/action.cpp \
    mechanics/project.cpp \
    mechanics/timer.cpp \
    mechanics/projecttarget.cpp \
    game/planets/planet.cpp \
    game/planets/colonizable.cpp \
    mechanics/stockpile.cpp \
    game/planets/planetgenerationstat.cpp \
    planetdialog.cpp \
    mechanics/mechanicsengine.cpp \
    mechanics/enginemodule.cpp \
    game/gamemodule.cpp \
    game/ui/holdingslist.cpp \
    game/actions/buildmineaction.cpp \
    game/buildings/building.cpp \
    game/buildings/mine.cpp \
    game/actions/teamproject.cpp \
    game/actions/gameproject.cpp \
    game/actions/teamprojectmanager.cpp \
    game/ui/uimodule.cpp \
    game/ui/clickableprogressbar.cpp \
    projectmenu.cpp \
    game/ui/uiobject.cpp \
    game/actions/cancelbuildaction.cpp \
    game/ui/colonizablelistwidgetitem.cpp \
    game/accademia/accademia.cpp \
    game/accademia/accademiagroups.cpp \
    game/accademia/accademiateam.cpp \
    corpinfo.cpp \
    game/actions/buyteamaction.cpp \
    game/actions/fireteamaction.cpp



HEADERS  += mainwindow.h \
    mechanics/characteristic.h \
    mechanics/rawbonus.h \
    render/renderState/renderstate.h \
    render/renderState/blending.h \
    render/renderState/colormask.h \
    render/renderState/depthrange.h \
    render/renderState/depthtest.h \
    render/renderState/faceculling.h \
    render/renderState/primitiverestart.h \
    render/renderState/scisortest.h \
    render/renderState/stenciltest.h \
    render/renderState/stenciltestface.h \
    render/glwidget.h \
    mechanics/entity.h \
    game/visibleentity.h \
    render/renderobject.h \
    render/transform3d.h \
    render/device.h \
    render/test/testQuad.h \
    render/input.h \
    render/camera3d.h \
    render/engineobject.h \
    render/defaultinputmanager.h \
    render/scene.h \
    render/defaultscene.h \
    game/galaxy.h \
    game/galaxyscene.h \
    game/galaxygenerator.h \
    render/texturedobject.h \
    game/galaxyfloor.h \
    render/dottedobject.h \
    render/textureswarmobject.h \
    game/gamewall.h \
    game/wall.h \
    game/wallscene.h \
    game/gamesupercluster.h \
    game/supercluster.h \
    game/superclusterscene.h \
    game/utils/cubeobject.h \
    render/linesobject.h \
    game/utils/grid.h \
    render/trisobject.h \
    game/utils/internalcube.h \
    game/gamescenes.h \
    game/gamedata.h \
    game/gamecluster.h \
    game/cluster.h \
    game/clusterscene.h \
    game/utils/connectlines.h \
    game/gamegalaxy.h \
    render/floatingquad.h \
    render/dot.h \
    game/gamesegment.h \
    game/segment.h \
    game/segmentscene.h \
    mechanics/action.h \
    mechanics/project.h \
    mechanics/timer.h \
    mechanics/projecttarget.h \
    game/planets/planet.h \
    game/planets/colonizable.h \
    mechanics/stockpile.h \
    game/planets/planetgenerationstat.h \
    planetdialog.h \
    mechanics/mechanicsengine.h \
    mechanics/enginemodule.h \
    game/gamemodule.h \
    game/ui/holdingslist.h \
    game/actions/buildmineaction.h \
    game/buildings/building.h \
    game/buildings/mine.h \
    game/actions/teamproject.h \
    game/actions/gameproject.h \
    game/actions/teamprojectmanager.h \
    game/ui/uimodule.h \
    game/ui/clickableprogressbar.h \
    projectmenu.h \
    game/ui/uiobject.h \
    game/actions/cancelbuildaction.h \
    game/ui/colonizablelistwidgetitem.h \
    game/accademia/accademia.h \
    game/accademia/accademiagroups.h \
    game/accademia/accademiateam.h \
    corpinfo.h \
    game/actions/buyteamaction.h \
    game/actions/fireteamaction.h


FORMS    += mainwindow.ui \
    planetdialog.ui \
    projectmenu.ui \
    corpinfo.ui

RESOURCES += \
    resources.qrc

