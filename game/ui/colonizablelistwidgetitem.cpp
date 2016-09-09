#include "colonizablelistwidgetitem.h"
#include "planetdialog.h"

using namespace game;
ColonizableListWidgetItem::ColonizableListWidgetItem(QString name, Colonizable* col, QListWidget* w, TeamProjectManager *man) :
    QListWidgetItem(name, w, 10000),
    colonizable(col),
    manager(man)
{

}

ColonizableListWidgetItem::~ColonizableListWidgetItem()
{

}

void ColonizableListWidgetItem::showDialog()
{
    PlanetDialog p(colonizable, manager);
    p.setModal(true);
    p.exec();

}
