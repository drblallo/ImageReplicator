#pragma once
#include "render/linesobject.h"
#include "render/engineobject.h"
#include <vector>
#include "render/textureswarmobject.h"

using namespace renderer;
namespace game
{
    class ConnectLines : public LinesObject
    {
        public:
            ConnectLines(std::vector<Dot> *points);
            virtual ~ConnectLines();

    };
}
