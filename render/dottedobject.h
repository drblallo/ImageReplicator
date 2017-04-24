#pragma once
#include <QVector3D>
#include <vector>
#include <render/renderobject.h>
#include <string>
#include "dot.h"

class QOpenGLShaderProgram;
namespace renderer
{

    class DottedObject : public RenderObject
    {
        public:
        //########################################
        //##### Constructors and Conversions #####
        //########################################
            DottedObject(const std::vector<Dot>* dots);
            virtual ~DottedObject();

        //########################################
        //#####         Privatizing          #####
        //########################################
            DottedObject(const DottedObject&) = delete;
            DottedObject& operator= (const DottedObject&) = delete;

        //########################################
        //#####           Methods            #####
        //########################################
            void setDots(const std::vector<Dot>* dots);
            virtual bool hitted(const QVector3D*, const QVector3D*) const {return false;}
            static QOpenGLShaderProgram* getShader();

        protected:
        //########################################
        //#####         Accessors            #####
        //########################################
            virtual GLenum getRenderMode() const ;
            virtual int getVertexCount()const {return vCount;}
            static QOpenGLShaderProgram* shader;

        //########################################
        //#####           Fields             #####
        //########################################
            static std::string vertString;
            static std::string fragString;
            int vCount;

    };
}
