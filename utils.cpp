#include "utils.h"
#include <random>

void randomize(std::vector<float>* vec)
{
    int vCount = vec->size()/14;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, vCount);
    renderer::Dot d(QVector3D(0,0,0), QVector3D(0,0,0));

    int target(0);
    for (int a = 0; a < vCount; a++)
    {
        target = distribution(generator);
        for (unsigned int v = 0; v < 6; v++)
            swap((*vec)[target*14 + v], (*vec)[a*14 + v]);

        for (unsigned int v = 7; v < 13; v++)
            swap((*vec)[target*14 + v], (*vec)[a*14 + v]);
    }
}

void generateLines(vector<float>* ls, QImage* original, QImage* sobelImage)
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
                ls->push_back(1*b + (SCALA*distributionReal(generator)));
                ls->push_back(-1*a + (SCALA*distributionReal(generator)));
                ls->push_back(-10.0f - ((distributionReal(generator))*DEPTH));
                ls->push_back(v.x());
                ls->push_back(v.y());
                ls->push_back(v.z());
                //ls->push_back(((a*sobelImage->width()+b))*2);
                //ls->push_back((ls->size()-6)/7);
                ls->push_back(0);


                ls->push_back(1*b);
                ls->push_back(-1*a);
                ls->push_back(-10);
                ls->push_back(v.x());
                ls->push_back(v.y());
                ls->push_back(v.z());
                ls->push_back((ls->size()-13)/7);
                //ls->push_back(0);
            }
        }
    }

    randomize(ls);
    int t(ls->size()/DROPPED);
    while (t%7!=0)
    {
        t--;
    }
    ls->erase(ls->begin()+t, ls->end());


    /*int num(ls->size());
    for (int a = 0; a < num; a = a + 6)
    {

    }*/

}
