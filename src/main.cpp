#include <complex>
#include <iostream>
#include <vector>
#include "mandelbrot.h"

int main() {
    const std::vector<std::vector<bool>> img = mandelbrot::generateMandelbrot(
        std::complex<double>(-2, 2),
        std::complex<double>(2, -2),
        150
    );
    mandelbrot::printMandelbrot(img);
}
