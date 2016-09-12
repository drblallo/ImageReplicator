#include "colonizablelistwidgetitem.h"
#include "planetdialog.h"

using namespace game;
ColonizableListWidgetItem::ColonizableListWidgetItem(
        QString name,
        Colonizable* col,
        QListWidget* w,
        TeamProjectManager *man,
        GameModule* m
        ) :
    QListWidgetItem(name, w, 10000),
    colonizable(col),
    manager(man),
    module(m)
{

}

ColonizableListWidgetItem::~ColonizableListWidgetItem()
{

}

void ColonizableListWidgetItem::showDialog()
{
    PlanetDialog p(colonizable, manager, module);
    p.setModal(true);
    p.exec();

}
