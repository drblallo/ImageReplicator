#pragma once
#include <vector>

namespace game
{
    class UiObject
    {
        public:
            friend class UIModule;
            UiObject();
            virtual ~UiObject();

        private:
            virtual void update() = 0;
            static std::vector<UiObject*> existingObjects;
            static void updateAll();
    };
}
