#pragma once

namespace mechanics
{
    class EngineModule
    {
        public:
            friend class MechanicsEngine;
        //########################################
        //##### Constructors and Conversions #####
        //########################################
            EngineModule();
            virtual ~EngineModule();

        //########################################
        //#####         Privatizing          #####
        //########################################
            EngineModule(const EngineModule&) = delete;
            EngineModule& operator= (const EngineModule&) = delete;

        protected:
        //########################################
        //#####           Methods            #####
        //########################################
            virtual void tick() = 0;
    };
}
