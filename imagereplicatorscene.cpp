#include "imagereplicatorscene.h"
#include "globaldefines.h"
#include <cmath>

ImageReplicatorScene::ImageReplicatorScene(QImage *original, QImage *sobel, vector<float> *ls) :
    DefaultScene(),
    originalImage(original),
    sobelImage(sobel),
    ogg(ls)
{

    float divisor(min(SCALEX/sobelImage->width(), SCALEY/sobelImage->height()));

    //set the scale of the object so that it the same size as the screen
    Transform3D* t(ogg.getTransform());
    t->setScale(divisor, divisor, 1);

    //set the position of the object in the center of the screen
    divisor = divisor * 0.5f;
    QVector3D v(divisor * -1 * sobelImage->width(), divisor * sobelImage->height(),0);
    t->setTranslation(v);
}
