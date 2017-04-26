#pragma once
#include <vector>
#include "render/dot.h"
#include <QImage>
#include "globaldefines.h"

using namespace std;
using namespace renderer;

void randomize(std::vector<float> *vec);
void generateLines(vector<float> *ls, QImage* original, QImage* sobelImage);
