#include "imagereplicatorscene.h"
#include "globaldefines.h"

ImageReplicatorScene::ImageReplicatorScene(QImage *original, QImage *sobel, vector<Dot> *ls) :
    DefaultScene(),
    originalImage(original),
    sobelImage(sobel),
    ogg(ls)
{

    float divisor(0);

    if (SCALEX/sobelImage->width() < SCALEY/sobelImage->height())
        divisor = SCALEX/sobelImage->width();
    else
        divisor = SCALEY/sobelImage->height();

    ogg.getTransform()->setScale(divisor, divisor, 1);
    ogg.getTransform()->setTranslation(QVector3D(
                                           float(ogg.getTransform()->scale().x())/-2.0f*sobelImage->width(),
                                           float(ogg.getTransform()->scale().y())/2.0f*sobelImage->height(),
                                           0)
                                       );
}
