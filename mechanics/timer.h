#pragma once
#include "action.h"

namespace mechanics
{
    class Timer : public Action
    {
        public:
        //########################################
        //##### Constructors and Conversions #####
        //########################################
            Timer(int ttl);

        //########################################
        //#####          Accessors           #####
        //########################################
            inline int getTimeToLive() const {return tickLeft;}
            inline int getInitialTTL() const {return startTickConst;}

        //########################################
        //#####           Methods            #####
        //########################################

        protected:
            virtual void OnExpire() = 0;
            virtual void OnTick();
            virtual void execute();
            virtual ~Timer();

        //########################################
        //#####           Fields             #####
        //########################################
            int tickLeft;
            int startTickConst;


    };
}
