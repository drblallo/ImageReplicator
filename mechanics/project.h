#pragma once
#include "timer.h"
#include <QString>

namespace mechanics
{
    class ProjectTarget;
    class Project : public Timer
    {
        public:
            friend class ProjectTarget;
        //########################################
        //##### Constructors and Conversions #####
        //########################################

        //########################################
        //#####         Privatizing          #####
        //########################################
            Project(const Project&) = delete;
            Project& operator= (const Project&) = delete;

        //########################################
        //#####          Accessors           #####
        //########################################
            inline ProjectTarget* getTarget(){return target;}
            inline QString getName() const {return name;}
            virtual QString getDescriptiveName() const;

        protected:
        //########################################
        //#####           Fields             #####
        //########################################
            ProjectTarget* target;

        //########################################
        //#####           Methods            #####
        //########################################
            virtual void OnExpire();

        private:
            Project(ProjectTarget* target, QString n);
            QString name;
            virtual ~Project();




    };
}
