#ifndef PLANETDIALOG_H
#define PLANETDIALOG_H

#include <QDialog>
#include "game/planets/colonizable.h"
#include "game/actions/teamprojectmanager.h"
#include "game/ui/uiobject.h"

namespace Ui {
class PlanetDialog;
}

class PlanetDialog : public QDialog, public game::UiObject
{
    Q_OBJECT

public:
    explicit PlanetDialog(game::Colonizable* col,game::TeamProjectManager* man ,QWidget *parent = 0);
    virtual ~PlanetDialog();

private slots:
    void on_ButtonBuildMine_clicked();

private:
    Ui::PlanetDialog *ui;
    game::Colonizable* colonizable;
    game::TeamProjectManager* manager;
    void updateDeposits();
    void updateBuildings();
    void updateOutputs();

protected:
    virtual void update();
};

#endif // PLANETDIALOG_H
