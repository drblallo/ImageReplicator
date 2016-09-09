#pragma once
#include "render/scene.h"
#include <vector>
#include "render/defaultinputmanager.h"
#include "wall.h"
#include "gamewall.h"
#include "utils/cubeobject.h"
#include "utils/grid.h"

namespace renderer
{
    class RenderObject;
}
using namespace renderer;
namespace game
{
    class WallScene: public renderer::Scene
    {
        public:
            WallScene();
            virtual ~WallScene();
            //inline GameWall* getWall(){return &wall;}

        protected:
        //########################################
        //#####           Methods            #####
        //########################################
            virtual void tearDown();
            virtual void setUp();
            std::vector<RenderObject*> spawned;
            DefaultInputManager manager;
           // GameWall wall;

            CubeObject cube;
            Grid grid;
            void clicked(int x, int y);
    };
}
