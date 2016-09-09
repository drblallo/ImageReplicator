#pragma once
#include "building.h"
#include <string>

namespace game
{
    class Mine : public Building
    {
        public:
            Mine(QString type);
            virtual ~Mine();
        private:
            RawBonus production;
    };
}
