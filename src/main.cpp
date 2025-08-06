#include <complex>
#include <iostream>
#include <vector>
#include "mandelbrot.h"
#include "color.h"
#include "bmp.h"

int main() {
    const std::vector<std::vector<color::Color>> img = mandelbrot::generateColoredMandelbrot(
        std::complex<double>(-1.15, 0.4),
        std::complex<double>(-0.85, 0.2),
        // std::complex<double>(-2, 1.25),
        // std::complex<double>(1, -1.25),
        3000,
        100,
        color::BLACK,
        color::BLUE_ORANGE
    );

    bmp::exportMatrix(img, "mandelbrot_img");
}
