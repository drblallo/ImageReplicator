#pragma once
#include <vector>
#include "render/dot.h"
#include <QImage>
#include "globaldefines.h"

using namespace std;
using namespace renderer;

void randomize(vector<Dot>* vec);
void generateLines(vector<Dot>* ls, QImage* original, QImage* sobelImage);
