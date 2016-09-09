#include "clickableprogressbar.h"
#include <iostream>

using namespace game;

ClickableProgressBar::ClickableProgressBar(QWidget *parent) : QProgressBar(parent), OnClicked(NULL)
{

}

ClickableProgressBar::~ClickableProgressBar()
{

}

void ClickableProgressBar::mousePressEvent(QMouseEvent *)
{
    if (OnClicked)
        OnClicked();
}

