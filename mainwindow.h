#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game/gamemodule.h"
#include "game/ui/uiobject.h"
#include "game/ui/uimodule.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public game::UiObject
{
    Q_OBJECT

public:
    explicit MainWindow(game::GameModule* modu);
    virtual ~MainWindow();
    bool eventFilter(QObject *watched, QEvent *event);
    static inline MainWindow* getMainWindow(){return mainWindow;}
    inline Ui::MainWindow* getUI(){return ui;}
    void startUI();

public slots:
    void openProjectMenu();

private:
    Ui::MainWindow *ui;
    game::GameModule* module;

    static MainWindow* mainWindow;
    game::UIModule* uimodule;

protected:
    virtual void update();
private slots:
    void on_MoneyButton_clicked();
};

#endif // MAINWINDOW_H
