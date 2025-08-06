#include <complex>
#include <iostream>
#include <vector>
#include "mandelbrot.h"
#include "color.h"
#include "bmp.h"

int main() {
    // const std::vector<std::vector<double>> img = mandelbrot::generateMandelbrot(
    //     std::complex<double>(-2, 1),
    //     std::complex<double>(1, -1),
    //     200,
    //     100
    // );
    // mandelbrot::printMandelbrot(img);
    const std::vector<std::vector<color::Color>> img = mandelbrot::generateColoredMandelbrot(
        std::complex<double>(-1, 0.3),
        std::complex<double>(-0.95, 0.2),
        2000,
        100,
        {0, 0, 0},
        color::sampleColors
    );

    bmp::exportMatrix(img, "mandelbrot_img");
}
