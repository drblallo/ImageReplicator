#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "kernels.h"

void gaussian_kernel(float);
void magnitude(QImage&, const QImage&, const QImage&);
QImage convolution(const matrix&, const QImage&);
QImage canny(const QImage&, float, float, float);
QImage sobel(const QImage&);
QImage prewitt(const QImage&);
QImage roberts(const QImage&);
QImage scharr(const QImage&);
QImage hysteresis(const QImage&, float, float);

#endif // ALGORITHMS_H
