#pragma once
#include "render/dot.h"
#include "render/floatingquad.h"
#include <vector>

using namespace renderer;
using namespace std;
namespace game
{
    class GameSegment
    {
        public:
            GameSegment(int x, int y);
            inline int getSegmentX(){return xAdress;}
            inline int getSegmentY(){return yAdress;}
            inline vector<Dot>* getDots(){return &dots;}
            inline vector<FloatingQuad>* getQuads(){return &quads;}

        private:
            int xAdress;
            int yAdress;
            vector<Dot> dots;
            Dot getCorrenspondant(vector<Dot>* zones[3][3],
                    uniform_real_distribution<double> distribution,
                    int a,
                    int b,
                    default_random_engine generator,
                    default_random_engine generator2
                , bool *found);
            vector<FloatingQuad> quads;
    };
}
