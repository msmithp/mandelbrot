#include "mandelbrot.h"
#include <complex>
#include <vector>
#include <iostream>

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

    std::vector<std::vector<bool>> generateMandelbrot(
        std::complex<double> topLeft, 
        std::complex<double> bottomRight,
        int imgWidth
    ) {
        const double verticalDistance = bottomRight.imag() - topLeft.imag();
        const double horizontalDistance = bottomRight.real() - topLeft.real();

        const double pixelWidth = horizontalDistance / imgWidth;
        const int imgHeight = (int) (horizontalDistance / pixelWidth);

        const double offsetReal = topLeft.real();
        const double offsetImag = topLeft.imag();

        std::vector<std::vector<bool>> img(
            imgHeight, std::vector<bool>(imgWidth)
        );

        for (int i = 0; i < imgHeight; i++) {
            for (int j = 0; j < imgWidth; j++) {
                const double real = (j * pixelWidth) + offsetReal;
                const double imag = -(i * pixelWidth) + offsetImag;
                const std::complex<double> num(real, imag);

                img[i][j] = isInMandelbrot(num);
            }
        }

        return img;
    }

    void printMandelbrot(std::vector<std::vector<bool>> img) {
        if (img.size() == 0) {
            return;
        }

        const int numRows = img.size();
        const int numCols = img[0].size();

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                const char symbol = img[i][j] ? '#' : ' ';
                std::cout << symbol;
            }

            std::cout << std::endl;
        }
    }
}