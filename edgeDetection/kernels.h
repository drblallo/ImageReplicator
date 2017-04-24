#ifndef KERNELS_H
#define KERNELS_H
#include <vector>

typedef std::vector<std::vector<float>> matrix;
const matrix sobelx {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
const matrix sobely {{1, 2, 1}, {0, 0, 0}, {-1, -2, -1}};
const matrix prewittx {{-1, 0, 1}, {-1, 0, 1}, {-1, 0, 1}};
const matrix prewitty {{-1, -1, -1}, {0, 0, 0}, {1, 1, 1}};
const matrix robertsx {{1, 0}, {0, -1}};
const matrix robertsy {{0, 1}, {-1, 0}};
const matrix scharrx {{3, 10, 3}, {0, 0, 0}, {-3, -10, -3}};
const matrix scharry {{3, 0, -3}, {10, 0, -10}, {3, 0, -3}};

#endif // KERNELS_H
