#ifndef BMP_H
#define BMP_H

#include "color.h"
#include <vector>
#include <string>
#include <array>

namespace bmp {
    const int BYTES_PER_PIXEL = 3;
    const int FILE_HEADER_SIZE = 14;
    const int INFO_HEADER_SIZE = 40;

    /**
     * @brief Export a matrix of RGB values as a .bmp file
     * 
     * @param img Matrix of colors, as RGB values
     * @param fileName Name of exported file, excluding the `.bmp` file
     *                 extension
     */
    void exportMatrix(
        std::vector<std::vector<color::Color>> img,
        std::string fileName
    );

    /**
     * @brief Create a .bmp file header
     * 
     * @param height Height of image, in pixels
     * @param stride Stride of image (width plus padding), in pixels
     * @return File header
     */
    std::array<unsigned char, FILE_HEADER_SIZE> createFileHeader(
        int height,
        int stride
    );

    /**
     * @brief Create a .bmp info header
     * 
     * @param height Height of image, in pixels
     * @param width Width of image (not including padding), in pixels
     * @return Info header
     */
    std::array<unsigned char, INFO_HEADER_SIZE> createInfoHeader(
        int height,
        int width
    );
}

#endif