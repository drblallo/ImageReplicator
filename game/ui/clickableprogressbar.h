#pragma once
#include <QProgressBar>
#include <functional>

namespace game
{
    class ClickableProgressBar : public QProgressBar
    {
       // Q_OBJECT
        public:
            explicit ClickableProgressBar(QWidget* parent) ;
            virtual ~ClickableProgressBar();
            std::function<void()> OnClicked;

        protected:
            void mousePressEvent(QMouseEvent* event);
    };
}
