#ifndef PROJECTMENU_H
#define PROJECTMENU_H

#include <QDialog>
#include "game/ui/uiobject.h"

namespace Ui {
class ProjectMenu;
}

namespace game
{
    class GameModule;
}

class ProjectMenu : public QDialog, public game::UiObject
{
    Q_OBJECT

public:
    explicit ProjectMenu(QWidget *parent = 0);
    explicit ProjectMenu(game::GameModule* modu);
    virtual ~ProjectMenu();

private:
    Ui::ProjectMenu *ui;
    game::GameModule* module;
    void updateProjects();
    void updateOperations();

protected:
    virtual void update();
private slots:
    void on_CancelProjectButton_clicked();
    void on_ButtonCancelOperation_clicked();
};

#endif // PROJECTMENU_H
