#pragma once
#include <QListWidget>

namespace game
{
    class HoldingsList : public QListWidget
    {
        public:
            HoldingsList(QWidget *parent);
            virtual ~HoldingsList();
            static HoldingsList* getList(){return list;}

        public slots:
            void openColonizableDialog(QListWidgetItem* item);

        private:
            static HoldingsList* list;
    };
}
