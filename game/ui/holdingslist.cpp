#include "holdingslist.h"
#include <iostream>
#include <functional>
#include "colonizablelistwidgetitem.h"

using namespace game;

HoldingsList* HoldingsList::list(NULL);
HoldingsList::HoldingsList(QWidget* parent) : QListWidget(parent)
{
    list = this;
    connect(this, &QListWidget::itemDoubleClicked, this, &HoldingsList::openColonizableDialog);

}

HoldingsList::~HoldingsList()
{

}

void HoldingsList::openColonizableDialog(QListWidgetItem *item)
{
    ColonizableListWidgetItem* t(dynamic_cast<ColonizableListWidgetItem*>(item));
    if (t)
    {
        t->showDialog();
    }
}
