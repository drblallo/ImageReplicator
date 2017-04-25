#include "utils.h"
#include <random>

void randomize(std::vector<renderer::Dot>* vec)
{
    int vCount = vec->size()/2;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, vCount);
    renderer::Dot d(QVector3D(0,0,0), QVector3D(0,0,0));

    for (int a = 0; a < vCount; a++)
    {
        int target(distribution(generator));
        d = (*vec)[target*2];
        (*vec)[target*2] = (*vec)[a*2];
        (*vec)[a*2] = d;

        d = (*vec)[target*2+1];
        (*vec)[target*2+1] = (*vec)[a*2+1];
        (*vec)[a*2+1] = d;
    }
}

void generateLines(vector<Dot>* ls, QImage* original, QImage* sobelImage)
{
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distributionReal(0, 1);
    for (int a = 0; a < sobelImage->height(); a++)
    {
        QRgb* line((QRgb*)(sobelImage->scanLine(a)));
        QRgb* lc((QRgb*)(original->scanLine(a)));

        for (int b = 0; b < sobelImage->width(); b++)
        {
            QColor col(qRed(line[b]), qGreen(line[b]), qBlue(line[b]));
            QColor originCol(qRed(lc[b]), qGreen(lc[b]), qBlue(lc[b]));
            if (col.red() > TRESH || col.green() > TRESH || col.blue() > TRESH)
            {
                QVector3D v(float(originCol.red())/255.0f, float(originCol.green())/255.0f, float(originCol.blue())/255.0f);
                ls->push_back(renderer::Dot(QVector3D(1*b, -1*a, -10), v));

                ls->push_back(renderer::Dot(
                                 QVector3D(
                                     1*b + (SCALA*distributionReal(generator)),
                                     -1*a + (SCALA*distributionReal(generator)),
                                     -10.0f + ((distributionReal(generator))*-1*DEPTH)
                                     ),
                                 v)
                             );
            }
        }
    }

    randomize(ls);
    ls->erase(ls->begin()+ls->size()/DROPPED, ls->end());

}
