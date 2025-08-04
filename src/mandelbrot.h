#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <complex>

namespace mandelbrot {
    /**
     * @brief Basic function for Mandelbrot set, `f_c(z) = z^2 + c`
     * 
     * @param z Complex number input to function
     * @param c Complex number
     */
    std::complex<double> mandelbrot(std::complex<double> z, std::complex<double> c);

    
    bool isInMandelbrot(std::complex<double> num);
}

#endif