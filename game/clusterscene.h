#pragma once
#include <vector>
#include "render/defaultinputmanager.h"
#include "render/scene.h"
#include "utils/internalcube.h"
#include "utils/grid.h"

namespace renderer
{
    class RenderObject;
}
using namespace renderer;
namespace game
{
    class Cluster;
    class ClusterScene : public Scene
    {
        public:
            ClusterScene();
            virtual ~ClusterScene();
            virtual void update();

        protected:
        //########################################
        //#####           Methods            #####
        //########################################
            virtual void tearDown();
            virtual void setUp();

            Cluster* cluster;
            std::vector<RenderObject*> spawned;
            DefaultInputManager manager;
            InternalCube cube;
            Grid grid;
            void clicked(int x, int y);
    };
}
