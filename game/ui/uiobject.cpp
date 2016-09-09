#include "uiobject.h"
#include <algorithm>


using namespace game;

std::vector<UiObject*> UiObject::existingObjects;
UiObject::UiObject()
{
    existingObjects.push_back(this);
}

UiObject::~UiObject()
{
    existingObjects.erase(remove(existingObjects.begin(), existingObjects.end(), this), existingObjects.end());
}

void UiObject::updateAll()
{
   std::vector<UiObject*> ogg(existingObjects);
   for (int a = 0; a < ogg.size(); a++)
       ogg[a]->update();
}

