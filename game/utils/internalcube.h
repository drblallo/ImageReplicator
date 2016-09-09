#pragma once
#include "render/trisobject.h"
#include "render/engineobject.h"

using namespace renderer;
namespace game
{
    class InternalCube: public TrisObject
    {
        public:
            InternalCube();
            virtual ~InternalCube();

        private:
            static std::vector<Dot>* getLines();
            static std::vector<Dot> lines;
    };
}
