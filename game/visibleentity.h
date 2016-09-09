#pragma once
#include "mechanics/entity.h"

using namespace mechanics;
namespace renderer
{
    class Scene;
}
using namespace renderer;

namespace game
{
    class VisibleEntity : public Entity
    {
        public:
        //########################################
        //##### Constructors and Conversions #####
        //########################################
            VisibleEntity();
            virtual ~VisibleEntity();

        //########################################
        //#####           Methods            #####
        //########################################
            virtual Scene* getScene() = 0;

        //########################################
        //#####         Privatizing          #####
        //########################################
            VisibleEntity(const VisibleEntity&) = delete;
            VisibleEntity& operator= ( const VisibleEntity&) = delete;
    };
}
