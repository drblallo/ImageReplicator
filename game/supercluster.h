#pragma once
#include "render/dottedobject.h"

using namespace renderer;
namespace game
{
    class GameSuperCluster;
    class SuperCluster : public DottedObject
    {
        public:
            SuperCluster(GameSuperCluster* superCluster);
            virtual ~SuperCluster();

        private:
            GameSuperCluster* superCluster;
    };
}
