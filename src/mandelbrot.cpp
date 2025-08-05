#include "mandelbrot.h"
#include <complex>
#include <vector>
#include <iostream>

namespace mandelbrot {
    std::complex<double> mandelbrot(std::complex<double> z,
        std::complex<double> c) {
        return std::pow(z, 2) + c;
    }

    bool isInMandelbrot(std::complex<double> num, int maxIterations) {
        return mandelbrotIterations(num, maxIterations) == -1;
    }

    int mandelbrotIterations(std::complex<double> num, int maxIterations) {
        std::complex<double> current = 0;
        for (int i = 0; i < maxIterations; i++) {
            current = mandelbrot(current, num);

            if (std::abs(current) > 2) {
                // Return number of iterations it took for number to grow
                // beyond 2
                return i;
            }
        }

        // Number never grew beyond 2, so return -1
        return -1;
    }

    std::vector<std::vector<bool>> generateBinaryMandelbrot(
        std::complex<double> topLeft, 
        std::complex<double> bottomRight,
        int imgWidth,
        int maxIterations
    ) {
        // Get dimensions of image, in units of the complex plane
        const double verticalDistance = bottomRight.imag() - topLeft.imag();
        const double horizontalDistance = bottomRight.real() - topLeft.real();

        // Get width of a pixel in the resulting image, in the complex plane
        const double pixelWidth = horizontalDistance / imgWidth;
        const int imgHeight = (int) (horizontalDistance / pixelWidth);

        // Because image coordinates start at (0, 0), we offset the starting
        // point to start at the top left
        const double offsetReal = topLeft.real();
        const double offsetImag = topLeft.imag();

        std::vector<std::vector<bool>> img(
            imgHeight, std::vector<bool>(imgWidth)
        );

        for (int i = 0; i < imgHeight; i++) {
            for (int j = 0; j < imgWidth; j++) {
                // Real part (analogous to x-value) increases (goes from left
                // to right) starting from offset
                const double real = (j * pixelWidth) + offsetReal;
                // Imaginary part (analogous to y-balue) increases (goes from
                // top to bottom) starting from offset
                const double imag = -(i * pixelWidth) + offsetImag;
                const std::complex<double> num(real, imag);

                img[i][j] = isInMandelbrot(num, maxIterations);
            }
        }

        return img;
    }

    std::vector<std::vector<double>> generateMandelbrot(
        std::complex<double> topLeft,
        std::complex<double> bottomRight,
        int imgWidth,
        int maxIterations
    ) {
        // Get dimensions of image, in units of the complex plane
        const double verticalDistance = bottomRight.imag() - topLeft.imag();
        const double horizontalDistance = bottomRight.real() - topLeft.real();

        // Get width of a pixel in the resulting image, in the complex plane
        const double pixelWidth = horizontalDistance / imgWidth;
        const int imgHeight = (int) (horizontalDistance / pixelWidth);

        // Because image coordinates start at (0, 0), we offset the starting
        // point to start at the top left
        const double offsetReal = topLeft.real();
        const double offsetImag = topLeft.imag();

        std::vector<std::vector<double>> img(
            imgHeight, std::vector<double>(imgWidth)
        );

        for (int i = 0; i < imgHeight; i++) {
            for (int j = 0; j < imgWidth; j++) {
                // Real part (analogous to x-value) increases (goes from left
                // to right) starting from offset
                const double real = (j * pixelWidth) + offsetReal;
                // Imaginary part (analogous to y-balue) increases (goes from
                // top to bottom) starting from offset
                const double imag = -(i * pixelWidth) + offsetImag;
                const std::complex<double> num(real, imag);

                int numIterations = mandelbrotIterations(num, maxIterations);

                if (numIterations < 0) {
                    // Number does not grow infinitely
                    img[i][j] = numIterations;
                } else {
                    // Number grows infinitely, so set img[i][j] to a value
                    // between 0 and 1 representing how long it took to grow
                    // larger than 2
                    img[i][j] = ((double) numIterations) / maxIterations;
                }
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

    void printMandelbrot(std::vector<std::vector<double>> img) {
        if (img.size() == 0) {
            return;
        }

        const int numRows = img.size();
        const int numCols = img[0].size();

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                const double val = img[i][j];
                if (val < 0) {
                    std::cout << '#';
                } else if (val < 0.2) {
                    std::cout << ' ';
                } else if (val < 0.4) {
                    std::cout << '.';
                } else if (val < 0.6) {
                    std::cout << ',';
                } else if (val < 0.8) {
                    std::cout << '-';
                } else {
                    std::cout << '*';
                }
            }

            std::cout << std::endl;
        }
    }
}