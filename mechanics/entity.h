#pragma once
#include <string>

namespace mechanics
{
    class Entity
    {
        public:
        //########################################
        //##### Constructors and Conversions #####
        //########################################
            Entity();
            virtual ~Entity();

        //########################################
        //#####          Accessors           #####
        //########################################
            virtual const std::string* getToolTip() = 0;

        //########################################
        //#####         Privatizing          #####
        //########################################
            Entity(const Entity&) = delete;
            Entity& operator= ( const Entity&) = delete;
    };
}
