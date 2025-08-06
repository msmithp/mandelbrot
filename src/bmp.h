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

    void exportMatrix(
        std::vector<std::vector<color::Color>> img,
        std::string fileName
    );

    std::array<unsigned char, FILE_HEADER_SIZE> createFileHeader(
        int height,
        int stride
    );

    std::array<unsigned char, INFO_HEADER_SIZE> createInfoHeader(
        int height,
        int width
    );
}

#endif