#include <complex>
#include <iostream>
#include <vector>
#include "mandelbrot.h"
#include "color.h"
#include "bmp.h"

int main() {
    const std::vector<std::vector<color::Color>> img = mandelbrot::generateColoredMandelbrot(
        std::complex<double>(-2, 1.25),
        std::complex<double>(1, -1.25),
        1000,
        100,
        {0, 0, 0},
        color::sampleColors
    );

    bmp::exportMatrix(img, "mandelbrot_img");
}
