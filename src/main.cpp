#include <complex>
#include <iostream>
#include <vector>
#include "mandelbrot.h"

int main() {
    const std::vector<std::vector<double>> img = mandelbrot::generateMandelbrot(
        std::complex<double>(-2, 1),
        std::complex<double>(1, -1),
        200,
        100
    );
    mandelbrot::printMandelbrot(img);
}
