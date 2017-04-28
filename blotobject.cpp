#include "blotobject.h"
#include "render/device.h"
#include <random>
#include <QOpenGLTexture>
#include <iostream>
#include <QVector2D>
#include <globalsettings.h>

std::string BlotObject::textureString(":/texture/nebula.png");
QOpenGLTexture* BlotObject::texture(NULL);

BlotObject::BlotObject(
		std::vector<FloatingQuad>* quads,
	   	QImage* image) : 
	TextureSwarmObject(quads, getTexture()),
	sourceImage(image)
{
	std::cerr << "created texture base" << std::endl; 
	transform.setScale(1, 1, 1);
	transform.setTranslation(0, 0, -10);
}

void BlotObject::makeQuads(std::vector<FloatingQuad>* vec, QImage* image)
{
	std::default_random_engine engine;
	std::uniform_int_distribution<int> heightDist(0, image->height()-1);
	std::uniform_int_distribution<int> widthDist(0, image->width()-1);

	float scaleX(GlobalSettings::getSettings()->blot_scale_x);
	float scaleY(GlobalSettings::getSettings()->blot_scale_y);

	for (int a = 0; a < GlobalSettings::getSettings()->blot_quantity; a++)
	{
		int x(widthDist(engine));
		int y(heightDist(engine));

		Transform3D transf;
		QRgb pixel(image->pixel(x, y));
		QVector4D col(qRed(pixel), qGreen(pixel), qBlue(pixel), 1);
		transf.setScale(scaleX, scaleY, 0);
		transf.setTranslation(
				x - (transf.scale().x()/2.0f),
			   	(-1*y) - (transf.scale().y()/2.0f),
			   	-15.0f + (0.1f*a)
				);

		FloatingQuad f(transf, col);		
		vec->push_back(f);
	}

}

QOpenGLTexture* BlotObject::getTexture()
{
	if (!texture)
	{
		texture = Device::createTexture(&textureString);
		texture->generateMipMaps();
		texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
		texture->setMagnificationFilter(QOpenGLTexture::Linear);
	}
	return texture;
}
