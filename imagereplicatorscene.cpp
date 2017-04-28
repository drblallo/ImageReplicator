#include "imagereplicatorscene.h"
#include "globaldefines.h"
#include <cmath>

ImageReplicatorScene::ImageReplicatorScene(QImage *original, QImage *sobel, bool showBlots) :
    DefaultScene(),
    originalImage(original),
    sobelImage(sobel),
	ogg(sobel, original),
	backGround(NULL)
{

    float divisor(min(SCALEX/sobelImage->width(), SCALEY/sobelImage->height()));

	if (showBlots)
	{
		vector<FloatingQuad> f;
		BlotObject::makeQuads(&f, originalImage);
		BlotObject* b = new BlotObject(&f, original);
		backGround = static_cast<shared_ptr<BlotObject> >(b);
	}

    //set the scale of the object so that it the same size as the screen
    Transform3D* t(ogg.getTransform());
    t->setScale(divisor, divisor, 1);

	if (showBlots)
		backGround->getTransform()->setScale(t->scale());

    //set the position of the object in the center of the screen
    divisor = divisor * 0.5f;
    QVector3D v(divisor * -1 * sobelImage->width(), divisor * sobelImage->height(),0);
    t->setTranslation(v);
	if (showBlots)
		backGround->getTransform()->setTranslation(t->translation());

}
