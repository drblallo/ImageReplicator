#pragma once
#include "render/defaultscene.h"
#include <QImage>
#include "appearinglines.h"

using namespace renderer;
using namespace std;
class ImageReplicatorScene : DefaultScene
{
    public:
        ImageReplicatorScene(QImage* original, QImage* sobel, vector<float>* ls);

    private:
        QImage* originalImage;
        QImage* sobelImage;
        AppearingLines ogg;
};
