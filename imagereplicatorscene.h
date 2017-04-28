#pragma once
#include "render/defaultscene.h"
#include <QImage>
#include "appearinglines.h"
#include "blotobject.h"
#include <memory>

using namespace renderer;
using namespace std;
class ImageReplicatorScene : DefaultScene
{
    public:
        ImageReplicatorScene(QImage* original, QImage* sobel, bool showBlots);

    private:
        QImage* originalImage;
        QImage* sobelImage;
        AppearingLines ogg;
		std::shared_ptr<BlotObject> backGround;
};
