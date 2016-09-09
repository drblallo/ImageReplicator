#pragma once
#include "gamewall.h"

namespace game
{
    class GameSuperCluster;
    class GameCluster;
    class GameGalaxy;
    class GameSegment;

    class GameData
    {
        public:
            inline static GameData* getData()
            {
                if (!data)
                    data = new GameData();

                return data;
            }

            inline GameWall* getWall(){return &wall;}
            void setSuperCluster(int targetSuperCluster);
            inline GameSuperCluster* getCurrentSuperCluster(){return superCluster;}

            void setCurrentCluster(int targetCluster);
            void setCurrentCluster(int x, int y);
            inline GameCluster* getCurrentCluster(){return cluster;}

            void setCurrentGalaxy(int targetGalaxy);
            inline GameGalaxy* getCurrentGalaxy(){return galaxy;}

            void setCurrentSegment(int x,int y);
            inline GameSegment* getCurrentSegment(){return segment;}


        private:
            GameData();
            static GameData* data;

            GameWall wall;
            GameSuperCluster* superCluster;
            GameCluster* cluster;
            GameGalaxy* galaxy;
            GameSegment* segment;

    };
}
