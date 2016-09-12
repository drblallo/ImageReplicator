#pragma once
#include <QListWidgetItem>
#include "game/planets/colonizable.h"
#include "game/gamemodule.h"

namespace game
{
    class TeamProjectManager;
    class ColonizableListWidgetItem : public QListWidgetItem
    {
        public:
            ColonizableListWidgetItem(QString name,
                                      Colonizable* col,
                                      QListWidget *w,
                                      TeamProjectManager* manager,
                                      game::GameModule *module);
            virtual ~ColonizableListWidgetItem();
            void showDialog();

        private:
            Colonizable* colonizable;
            TeamProjectManager* manager;
            GameModule* module;
    };
}
