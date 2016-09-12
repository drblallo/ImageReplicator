#include "corpinfo.h"
#include "ui_corpinfo.h"
#include "game/gamemodule.h"
#include "game/accademia/accademiagroups.h"
#include "game/accademia/accademia.h"
#include "game/actions/buyteamaction.h"
#include "game/actions/fireteamaction.h"

CorpInfo::CorpInfo(GameModule* modu, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CorpInfo),
    module(modu)
{
    ui->setupUi(this);
    update();
}

CorpInfo::~CorpInfo()
{
    delete ui;
}

void CorpInfo::update()
{
    updateHirebleList();
    updateHiredList();
}

void CorpInfo::updateHirebleList()
{
    int r(ui->ListHireble->currentRow());

    ui->ListHireble->clear();
    AccademiaGroups* acc(module->getAccademiaGroup());

    ui->LabelAccCountNum->setText(QString::number(acc->getAccademies()->size()));

    AccademiaTeam t;
    for (unsigned int a = 0; a < acc->getTeams()->size(); a++)
    {
        if (acc->isTeamBought(a))
        {
            new QListWidgetItem("HIRED TEAM", ui->ListHireble);
        }
        else
        {
            t = acc->getTeam(a);
            QString str(*t.getName());
            str.append("\t");
            str.append(t.getTypeName());
            str.append("\tLvl:");
            str.append(QString::number(t.getSkillLevel()));
            str.append("\t");
            str.append(QString::number(t.getCost()));
            new QListWidgetItem(str, ui->ListHireble);
        }
    }

    ui->ListHireble->setCurrentRow(r);
}

void CorpInfo::updateHiredList()
{
    int r(ui->ListHired->currentRow());
    ui->ListHired->clear();


    AccademiaTeam t;
    for (unsigned int a = 0; a < module->getTeams()->size(); a++)
    {
        t = module->getTeam(a);

        QString str(*t.getName());
        str.append("\t");
        str.append(t.getTypeName());
        str.append("\tLvl:");
        str.append(QString::number(t.getSkillLevel()));
        new QListWidgetItem(str, ui->ListHired);
    }

    ui->ListHired->setCurrentRow(r);

}

void CorpInfo::on_ButtonFired_clicked()
{
    int t(ui->ListHired->currentRow());
    new FireTeamAction(t, module ,module->getTeam(t));
}

void CorpInfo::on_ButtonHire_clicked()
{
    new BuyTeamAction(ui->ListHireble->currentRow(), module);
}
