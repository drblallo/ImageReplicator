#include "gameproject.h"

using namespace game;
GameProject::GameProject(int time, QString n) : ProjectTarget(time, n)
{

}

GameProject::~GameProject()
{

}

void GameProject::OnProjectComplete()
{
    OnProjectFinished();
}

