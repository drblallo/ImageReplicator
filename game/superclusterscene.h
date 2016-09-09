#pragma once
#include <vector>
#include "render/defaultinputmanager.h"
#include "render/scene.h"
#include "utils/cubeobject.h"
#include "utils/grid.h"

namespace renderer
{
    class RenderObject;
}
using namespace renderer;
namespace game
{
    class SuperCluster;
    class SuperClusterScene : public Scene
    {
        public:
            SuperClusterScene();
            virtual ~SuperClusterScene();
            virtual void update();

        protected:
        //########################################
        //#####           Methods            #####
        //########################################
            virtual void tearDown();
            virtual void setUp();

            SuperCluster* superCluster;
            std::vector<RenderObject*> spawned;
            DefaultInputManager manager;
            CubeObject cube;
            Grid grid;
            void clicked(int x, int y);
    };
}
