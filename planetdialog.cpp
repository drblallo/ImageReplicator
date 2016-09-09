#include "planetdialog.h"
#include "ui_planetdialog.h"
#include <QListWidgetItem>
#include <QString>
#include "game/actions/buildmineaction.h"

using namespace game;
PlanetDialog::PlanetDialog(game::Colonizable* col, TeamProjectManager* man, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlanetDialog),
    colonizable(col),
    manager(man)
{
    ui->setupUi(this);
    update();
}

void PlanetDialog::update()
{
    updateDeposits();
    updateBuildings();
}

void PlanetDialog::updateDeposits()
{
    int s(ui->ListDeposits->currentRow());

    ui->ListDeposits->clear();
    vector<mechanics::StockPile*> resoruces(colonizable->getMinable());
    for (unsigned int a = 0; a < resoruces.size(); a++)
    {
        QString str(resoruces[a]->getName()->c_str());
        str.append("\t");
        str += QString::number(resoruces[a]->getValue());

        new QListWidgetItem(str, ui->ListDeposits);

    }

    ui->ListDeposits->setCurrentRow(s);
}

void PlanetDialog::updateBuildings()
{
    int s(ui->ListStructures->currentRow());

    ui->ListStructures->clear();
    vector<std::shared_ptr<Building> > resoruces(colonizable->getBuildings());

    for (unsigned int a = 0; a < resoruces.size(); a++)
    {
        QString str(*resoruces[a]->getName());

        new QListWidgetItem(str, ui->ListStructures);
    }

    ui->ListStructures->setCurrentRow(s);
}

PlanetDialog::~PlanetDialog()
{
    delete ui;
}

void PlanetDialog::on_ButtonBuildMine_clicked()
{
     new BuildMineAction(colonizable, ui->ListDeposits->currentRow(), "Project Build Mine", manager);
   // m->getProject()->call();
}
