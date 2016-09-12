#pragma once
#include "characteristic.h"
#include "project.h"

namespace mechanics
{
    class ProjectTarget
    {
        public:
            friend class Project;
        //########################################
        //##### Constructors and Conversions #####
        //########################################
            ProjectTarget(int baseTimeToCreate, QString name);

        //########################################
        //#####         Privatizing          #####
        //########################################
            ProjectTarget(const ProjectTarget&) = delete;
            ProjectTarget& operator= (const ProjectTarget&) = delete;


        //########################################
        //#####          Accessors           #####
        //########################################
            inline Characteristic* getProjectTime() {return &projectTime;}
            inline Project* getProject(){return project;}
            inline QString getName() const {return name;}
            virtual QString getDescriptiveName() const;

        protected:
        //########################################
        //#####           Fields             #####
        //########################################
            Characteristic projectTime;
            Project* project;
            QString name;
            virtual ~ProjectTarget();


        //########################################
        //#####           Methods            #####
        //########################################
            virtual void OnProjectComplete() = 0;
            virtual void onProjectCanceled() = 0;
            virtual void OnProjectStart() = 0;
    };
}
