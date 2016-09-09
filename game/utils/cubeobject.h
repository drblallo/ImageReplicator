#pragma once
#include "render/engineobject.h"
#include "render/linesobject.h"
#include "internalcube.h"
#include <functional>

using namespace renderer;
namespace game
{
    class CubeObject : public LinesObject, public EngineObject
    {
        public:
            CubeObject(QVector3D size, QVector3D pos, std::function<void (int, int)> fun);
            virtual ~CubeObject();
            inline InternalCube* getCube(){return &internal;}
            inline void setCallback(std::function<void (int, int)> fun){callBack = fun;}


        protected:
            virtual void Update();
            static std::vector<Dot>* getLines();
            static std::vector<Dot> lines;
            QVector3D offsett;
            InternalCube internal;
            std::function<void (int, int)> callBack;
    };
}
