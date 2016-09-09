#pragma once
#include "wallscene.h"
#include "superclusterscene.h"
#include "clusterscene.h"
#include "galaxyscene.h"
#include "segmentscene.h"

namespace game
{
    class GameScenes
    {
        public:
            inline static GameScenes* getScenes(){
                if(!scenes)
                    scenes = new GameScenes();
                return scenes;
            }

            WallScene wallScene;
            SuperClusterScene superClusterScene;
            ClusterScene clusterScene;
            GalaxyScene galaxyScene;
            SegmentScene segmentScene;

        private:
            static GameScenes* scenes;
            GameScenes();
    };
}
