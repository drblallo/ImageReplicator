#include "planetdialog.h"
#include "ui_planetdialog.h"
#include <QListWidgetItem>
#include <QString>
#include "game/actions/buildmineaction.h"

using namespace game;
PlanetDialog::PlanetDialog(game::Colonizable* col, TeamProjectManager* man, GameModule* m, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlanetDialog),
    colonizable(col),
    manager(man),
    module(m)
{
    ui->setupUi(this);
    update();
}

void PlanetDialog::update()
{
    updateDeposits();
    updateBuildings();
    updateOutputs();
}

void PlanetDialog::updateOutputs()
{
    int s(ui->ListOutputs->currentRow());

    ui->ListOutputs->clear();
    const vector<Characteristic>* resoruces(colonizable->getOutPuts());
    for (unsigned int a = 0; a < resoruces->size(); a++)
    {
        QString str(QString::fromStdString(*resoruces->at(a).getName()));
        str.append("\t");
        str += QString::number(resoruces->at(a).getValue());

        new QListWidgetItem(str, ui->ListOutputs);

    }

    ui->ListOutputs->setCurrentRow(s);

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

    s = ui->BuildMineComboBox->currentIndex();
    ui->BuildMineComboBox->clear();

    for (unsigned int a = 0; a < module->getTeams()->size(); a++)
    {

        ui->BuildMineComboBox->addItem(
                    QString::number(module->getTeams()->at(a).getSkillLevel())
                    + "-" +
                    module->getTeams()->at(a).getTypeName()
                    + " "
                    + *module->getTeams()->at(a).getName()
                    );
    }


    ui->BuildMineComboBox->setCurrentIndex(s);
}

void PlanetDialog::updateBuildings()
{
    int s(ui->ListStructures->currentRow());

    ui->ListStructures->clear();
    vector<std::shared_ptr<Building> > resoruces(colonizable->getBuildings());

    for (unsigned int a = 0; a < resoruces.size(); a++)
    {
        QString str(resoruces[a]->getDescription());
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
    if (ui->BuildMineComboBox->currentIndex() >= 0)
    {
        new BuildMineAction
                (
                    colonizable,
                    ui->ListDeposits->currentRow(),
                    "Project Build Mine",
                    module,
                    module->getTeam(ui->BuildMineComboBox->currentIndex())
                );
    }
   // m->getProject()->call();
}
