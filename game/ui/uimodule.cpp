#include "uimodule.h"
#include "game/gamemodule.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game/actions/teamproject.h"
#include <iostream>
#include "uiobject.h"

using namespace game;
UIModule::UIModule(GameModule* mod, MainWindow *w)  : module(mod), mainWindow(w), toUpdate(true)
{
    std::cerr << "UI module attached\n";
}

UIModule::~UIModule()
{

}

void UIModule::tick()
{
    while (!m.try_lock())
        ;
    toUpdate = true;
    m.unlock();
}

void UIModule::Update()
{
    if (!m.try_lock())
        return;
    if (!toUpdate)
    {
        m.unlock();
        return;
    }
    std::cout << "updated ui\n";
    toUpdate = false;
    UiObject::updateAll();
    m.unlock();
}
