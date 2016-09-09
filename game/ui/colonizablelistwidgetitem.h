#pragma once
#include <QListWidgetItem>
#include "game/planets/colonizable.h"

namespace game
{
    class TeamProjectManager;
    class ColonizableListWidgetItem : public QListWidgetItem
    {
        public:
            ColonizableListWidgetItem(QString name, Colonizable* col, QListWidget *w, TeamProjectManager* manager);
            virtual ~ColonizableListWidgetItem();
            void showDialog();

        private:
            Colonizable* colonizable;
            TeamProjectManager* manager;
    };
}
