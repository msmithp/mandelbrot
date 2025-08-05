#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <complex>
#include <vector>

namespace mandelbrot {
    /**
     * @brief Basic function for Mandelbrot set, `f_c(z) = z^2 + c`
     * 
     * @param z Complex number input to function
     * @param c Complex number
     */
    std::complex<double> mandelbrot(std::complex<double> z,
        std::complex<double> c);

    /**
     * @brief Test if a complex number is in the Mandelbrot set
     * 
     * @param num Complex number
     * @return `true` if `num` is in the Mandelbrot set, `false` otherwise
     */
    bool isInMandelbrot(std::complex<double> num);

    /**
     * @brief Generate a graphical representation of the Mandelbrot set
     * 
     * @param topLeft Top left point (i.e., number with highest imaginary
     *                part and lowest real part)
     * @param bottomRight Bottom right point (i.e., number with lowest 
     *                    imaginary part and highest real part)
     * @param imgWidth Width of the resulting image (i.e., number of columns)
     * @return 2D vector in which `true` represents a point in the Mandelbrot
     *         set and `false` represents a point not in the Mandelbrot set
     */
    std::vector<std::vector<bool>> generateMandelbrot(
        std::complex<double> topLeft, 
        std::complex<double> bottomRight,
        int imgWidth
    );

    /**
     * @brief Print a visual representation of a Mandelbrot set
     * 
     * @param img Mandelbrot set, as a 2D vector of boolean values
     */
    void printMandelbrot(std::vector<std::vector<bool>> img);
}

#endif