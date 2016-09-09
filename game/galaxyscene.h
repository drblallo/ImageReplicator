#pragma once
#include "render/scene.h"
#include <vector>
#include "render/defaultinputmanager.h"
#include "render/dottedobject.h"
#include "render/textureswarmobject.h"
#include "utils/grid.h"
#include "utils/cubeobject.h"

namespace renderer
{
    class RenderObject;
}
using namespace renderer;
namespace game
{
    class GalaxyScene : public renderer::Scene
    {
        public:
            GalaxyScene();
            virtual ~GalaxyScene();
            virtual void update();

        protected:
        //########################################
        //#####           Methods            #####
        //########################################
            virtual void tearDown();
            virtual void setUp();
            std::vector<RenderObject*> spawned;
            void clicked(int x, int y);
         //   DefaultInputManager manager;

            Grid grid;
            CubeObject cube;

         //   std::vector<Dot> dots;
         //   std::vector<FloatingQuad> quads;
    };
}
