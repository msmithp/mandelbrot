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
     * @param num Complex number, value of `c` in `mandelbrot` function
     * @param maxIterations Max number of iterations for `mandelbrot` function
     * @return `true` if `num` is in the Mandelbrot set, `false` otherwise
     */
    bool isInMandelbrot(std::complex<double> num, int maxIterations);

    /**
     * @brief Count how many iterations of the `mandelbrot` function it takes
     *        for the absolute value of `num` to become greater than 2, 
     *        starting from 0
     * 
     * @param num Complex number, value of `c` in `mandelbrot` function
     * @param maxIterations Max number of iterations for `mandelbrot` function
     * @return Number of iterations, between 0 and `maxIterations`, for `num`
     *         to become greater than 2, or -1 if `num` never grows beyond 2
     */
    int mandelbrotIterations(std::complex<double> num, int maxIterations);

    /**
     * @brief Generate a graphical representation of the Mandelbrot set
     * 
     * @param topLeft Top left point (i.e., number with highest imaginary
     *                part and lowest real part)
     * @param bottomRight Bottom right point (i.e., number with lowest 
     *                    imaginary part and highest real part)
     * @param imgWidth Width of the resulting image (i.e., number of columns)
     * @param maxIterations Max number of iterations for `mandelbrot` function
     * @return 2D vector in which `true` represents a point in the Mandelbrot
     *         set and `false` represents a point not in the Mandelbrot set
     */
    std::vector<std::vector<bool>> generateBinaryMandelbrot(
        std::complex<double> topLeft, 
        std::complex<double> bottomRight,
        int imgWidth,
        int maxIterations
    );

    /**
     * @brief Generate a graphical representation of the Mandelbrot set
     * 
     * @param topLeft Top left point (i.e., number with highest imaginary
     *                part and lowest real part)
     * @param bottomRight Bottom right point (i.e., number with lowest 
     *                    imaginary part and highest real part)
     * @param imgWidth Width of the resulting image (i.e., number of columns)
     * @param maxIterations Max number of iterations for `mandelbrot` function
     * @return 2D vector of values between 0 and 1, or just -1, in which a -1
     *         represents a point in the Mandelbrot set, and a value between 0
     *         and 1 represents a value not in the Mandelbrot set, with higher
     *         values corresponding to points that took longer to grow larger
     *         than 2
     */
    std::vector<std::vector<double>> generateMandelbrot(
        std::complex<double> topLeft,
        std::complex<double> bottomRight,
        int imgWidth,
        int maxIterations
    );

    /**
     * @brief Print a visual representation of the Mandelbrot set in which a
     *        value is printed with a "#" if it is in the set and a " " if it
     *        is not
     * 
     * @param img Mandelbrot set, as a 2D vector of boolean values
     */
    void printMandelbrot(std::vector<std::vector<bool>> img);

    /**
     * @brief Print a visual representation of the Mandelbrot set in which
     *        values not in the set are given different characters based on
     *        how long it took them to grow beyond 2
     * 
     * @param img Mandelbrot set, as a 2D vector of values between 0 and 1,
     *            with values in the set represented with -1
     */
    void printMandelbrot(std::vector<std::vector<double>> img);
}

#endif