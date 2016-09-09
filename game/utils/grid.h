#pragma once
#include "render/linesobject.h"
#include "render/engineobject.h"

using namespace renderer;
namespace game
{
    class Grid : public LinesObject, public EngineObject
    {
        public:
            Grid(int num);
            Grid();
            virtual ~Grid();

        private:
            virtual void Update();
            static std::vector<Dot>* getLines(int t);
            static std::vector<Dot> lines;
            int n;
    };
}
