#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projectmenu.h"
#include <iostream>
#include <functional>
#include "game/actions/teamproject.h"
#include "game/planets/colonizable.h"
#include "game/ui/colonizablelistwidgetitem.h"

MainWindow* MainWindow::mainWindow(NULL);
using namespace game;


MainWindow::MainWindow(game::GameModule *p) :
    QMainWindow(NULL),
    ui(new Ui::MainWindow),
    module(p),
    uimodule(NULL)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    mainWindow = this;
    ui->ProjectProgress->OnClicked = std::bind(&MainWindow::openProjectMenu, this);
    startUI();

}

void MainWindow::startUI()
{
    uimodule =  new UIModule(module, this);
    module->generatePlanet();

}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::eventFilter(QObject *, QEvent *e)
{
    if(e->type() == QEvent::KeyPress)
    {
   //     qWarning() << "The bad guy which steals the keyevent is" << o;
    }
    return false;
}

void MainWindow::update()
{

    int t(ui->Holdings->currentRow());
    ui->Holdings->clear();
    TeamProject* project(module->getProjectManager()->getMostAdvancedProject());
    if (project && project->getProject())
    {
        ui->ProjectProgress->setMaximum(project->getProject()->getInitialTTL());
        ui->ProjectProgress->setValue(project->getProject()->getInitialTTL() - project->getProject()->getTimeToLive());
        ui->ProjectName->setText(project->getProject()->getName());
    }
    else
    {
        ui->ProjectProgress->setValue(0);
        ui->ProjectName->setText(QString("No Project"));
    }

    for (unsigned int a = 0; a < module->getHoldings()->size(); a++)
    {
        new ColonizableListWidgetItem(
                    QString::fromStdString(*module->getHolding(a)->getName()),
                    module->getHolding(a),
                    ui->Holdings,
                    module->getProjectManager());
    }

    ui->Holdings->setCurrentRow(t);
}

void MainWindow::openProjectMenu()
{
    std::cout << "calledtoo\n";
    if (!module)
        return;
    ProjectMenu p(module);
    p.setModal(true);
    p.exec();
}
