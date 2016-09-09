#pragma once
#include "render/dottedobject.h"
#include <vector>

using namespace std;
using namespace renderer;
namespace game {
    class GameSuperCluster
    {
        public:
            GameSuperCluster(int adress );
            inline const vector<Dot>* getDots() const {return &dots;}
            inline int getX() const {return adress%2;}
            inline int getY() const {return adress/2;}
            inline int getAdress() const {return adress;}
            inline vector<Dot*>* getCluster(int target)
            {
                if (target < 0 || target > 50*50)
                    return NULL;
                int x(target/50);
                int y(target%50);
                return &(ammassClusters[x][y]);
            }
            inline vector<Dot*>* getCluster(int x, int y)
            {
                if (x < 0 || y < 0 || x >49 || y > 49)
                    return NULL;
                return &(ammassClusters[x][y]);
            }

        private:
            const vector<Dot*>* wallDots;
            vector<Dot> dots;
            void generate(int adrs);
            int adress;

            vector<Dot*> ammassClusters[50][50];
    };
}
