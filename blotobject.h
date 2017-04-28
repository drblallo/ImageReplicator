#pragma once
#include "render/textureswarmobject.h"
#include <QImage>

using namespace renderer;
class BlotObject : public TextureSwarmObject
{
	public:
		BlotObject(
				std::vector<FloatingQuad>* quads,
			   	QImage* image
				);
		static void makeQuads(std::vector<FloatingQuad>* quads, QImage* image);

	private:
		QImage* sourceImage;
		static std::string textureString;
		static QOpenGLTexture* texture;
		static QOpenGLTexture* getTexture();

};
