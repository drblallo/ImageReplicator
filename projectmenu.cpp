#include "projectmenu.h"
#include "ui_projectmenu.h"
#include "game/gamemodule.h"
#include "game/actions/teamproject.h"
#include "game/actions/cancelbuildaction.h"

ProjectMenu::ProjectMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectMenu),
    module(NULL)
{
    ui->setupUi(this);
}


ProjectMenu::ProjectMenu(game::GameModule* modu) : QDialog(NULL), ui(new Ui::ProjectMenu), module(modu)
{
    ui->setupUi(this);

    update();
}

ProjectMenu::~ProjectMenu()
{
    delete ui;
}

void ProjectMenu::update()
{
    updateProjects();
    updateOperations();
}

void ProjectMenu::updateProjects()
{
    int t(ui->ListProjects->currentRow());
    ui->ListProjects->clear();
    ui->LabelMaxProjectCount->setText(QString::number(module->getProjectManager()->getMaxProjectsCount()));

    vector<Project*> projectes(module->getProjectManager()->getProjects());
    for (unsigned int a = 0; a < projectes.size(); a++)
    {
        new QListWidgetItem((projectes[a]->getDescriptiveName()), ui->ListProjects);
    }
    ui->ListProjects->setCurrentRow(t);

}

void ProjectMenu::updateOperations()
{
    int t(ui->ListOperations->currentRow());
    ui->ListOperations->clear();

    vector<game::TeamProject*> operations(module->getProjectManager()->getOperations());
    for (unsigned int a = 0; a < operations.size(); a++)
    {
        new QListWidgetItem(operations[a]->getDescriptiveName(), ui->ListOperations);
    }

    ui->ListOperations->setCurrentRow(t);

}

void ProjectMenu::on_CancelProjectButton_clicked()
{
    if (ui->ListProjects->currentRow() >= 0)
    {
        unsigned int t(ui->ListProjects->currentRow());
        mechanics::Project* p(module->getProjectManager()->getProjects()[t]);
        if (!p)
            return;

        if (p)
        {
            Action::uncall(p);
            updateProjects();
        }
    }
}


void ProjectMenu::on_ButtonCancelOperation_clicked()
{

    if (ui->ListOperations->currentRow() >= 0)
    {
        unsigned int t(ui->ListOperations->currentRow());
        game::TeamProject* p(module->getProjectManager()->getOperations()[t]);
        if (!p)
            return;

        //if (p->getProject())
         //   p->getProject()->uncall();
        if (p)
        {
            Action::uncall(p);
            updateOperations();
        }
    }
}
