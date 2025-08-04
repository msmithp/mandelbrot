#include "mandelbrot.h"
#include <complex>

namespace mandelbrot {
    bool isInMandelbrot(std::complex<double> num) {
        const int MAX_ITERATIONS = 100;

        std::complex<double> current = 0;
        for (int i = 0; i < MAX_ITERATIONS; i++) {
            current = mandelbrot(current, num);

            if (std::abs(current) > 2) {
                return false;
            }
        }

        return true;
    }

    std::complex<double> mandelbrot(std::complex<double> z,
        std::complex<double> c) {
        return std::pow(z, 2) + c;
    }
}