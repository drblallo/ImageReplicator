#pragma once
#include "render/textureswarmobject.h"
#include "render/dottedobject.h"
#define GALAXY_SLOT_SIZE 50

using namespace renderer;
using namespace std;
namespace game
{
    class GameGalaxy
    {
        public:
            GameGalaxy(int s);
            inline vector<Dot>* getDots() {return &dots;}
            inline vector<FloatingQuad>* getQuads() {return &quads;}
            inline int getSeed(){return seed;}
            inline vector<Dot>* getDotSlot(int x, int y)
            {
                if (x < 0 || x >= GALAXY_SLOT_SIZE || y < 0 || y >= GALAXY_SLOT_SIZE)
                    return NULL;
                return &(dotSlots[x][y]);
            }
            inline vector<FloatingQuad>* getQuadSlot(int x, int y)
            {
                if (x < 0 || x >= GALAXY_SLOT_SIZE || y < 0 || y >= GALAXY_SLOT_SIZE)
                    return NULL;
                return &(quadSlots[x][y]);
            }

        private:
            vector<Dot> dots;
            vector<FloatingQuad> quads;
            int seed;

            vector<Dot> dotSlots[GALAXY_SLOT_SIZE][GALAXY_SLOT_SIZE];
            vector<FloatingQuad> quadSlots[GALAXY_SLOT_SIZE][GALAXY_SLOT_SIZE];
    };
}
