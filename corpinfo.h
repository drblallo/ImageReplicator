#ifndef CORPINFO_H
#define CORPINFO_H

#include <QDialog>
#include <game/ui/uiobject.h>

namespace Ui {
class CorpInfo;
}

namespace game
{
    class GameModule;
}
using namespace game;
class CorpInfo : public QDialog, public game::UiObject
{
    Q_OBJECT

public:
    explicit CorpInfo(GameModule* mod, QWidget *parent = 0);
    ~CorpInfo();
    virtual void update();

private slots:
    void on_ButtonFired_clicked();

    void on_ButtonHire_clicked();

private:
    Ui::CorpInfo *ui;
    void updateHirebleList();
    void updateHiredList();
    GameModule* module;

};

#endif // CORPINFO_H
