#include "building.h"

using namespace game;
Building::Building(QString n, int maxLevel): maxUpgrade(maxLevel), currentLevel(1) ,name(n)
{

}

Building::Building(const QString* n, int maxLevel): maxUpgrade(maxLevel), currentLevel(1) ,name(*n)
{

}

Building::~Building()
{
    OnBuildingRemoved();
}

void Building::OnBuildingDowngraded()
{

}

void Building::OnBuildingRemoved()
{

}

void Building::OnBuildingUpgraded()
{

}

void Building::OnClicked()
{

}

QString Building::getDescription() const
{
    QString diRitorno(name);
    for (unsigned int a = 0; a < rawOutputs.size(); a++)
    {
        diRitorno += "\n";
        diRitorno += "\t";
        diRitorno += QString::fromStdString(*rawOutputs[a]->getDescription());
        diRitorno += ": ";
        diRitorno += QString::number(rawOutputs[a]->getValue());
    }
    for (unsigned int a = 0; a < percentOutputs.size(); a++)
    {
        diRitorno += "\n";
        diRitorno += "\t";
        diRitorno +=  QString::fromStdString(*percentOutputs[a]->getDescription());
        diRitorno += ": ";
        diRitorno += QString::number(rawOutputs[a]->getValue());
        diRitorno += "%";
    }
    return diRitorno;
}
