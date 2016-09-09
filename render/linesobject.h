#pragma once
#include "dottedobject.h"

namespace renderer
{
    class LinesObject : public DottedObject
    {
        public:
            LinesObject(std::vector<Dot>* lines);
            virtual ~LinesObject();

        protected:
            virtual GLenum getRenderMode() const {return GL_LINES;}
    };
}
