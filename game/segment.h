#pragma once
#include "render/dottedobject.h"
#include "galaxyfloor.h"

using namespace renderer;
namespace game
{
    class GameSegment;
    class Segment : public DottedObject
    {
        public:
            Segment(GameSegment* superCluster);
            virtual ~Segment();

        private:
            GalaxyFloor floor;

    };
}
