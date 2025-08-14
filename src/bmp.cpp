#include "bmp.h"
#include "color.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <array>

namespace bmp {
    void exportMatrix(
        const std::vector<std::vector<color::Color>>& img,
        const std::string& fileName
    ) {
        const int height = img.size();
        const int width = img[0].size();

        // Must pad out each row so the number of bytes in each row is a
        // multiple of 4
        const int widthInBytes = width * BYTES_PER_PIXEL;
        const int paddingSize = (4 - (widthInBytes % 4)) % 4;

        // True width of the image array, accounting for padding
        const int stride = widthInBytes + paddingSize;

        // Open file for output in binary mode
        std::ofstream ofs;
        ofs.open(fileName + ".bmp", std::ios::binary);

        // Write file header
        std::array<unsigned char, FILE_HEADER_SIZE> fileHeader
            = createFileHeader(height, stride);

        ofs.write(reinterpret_cast<char*>(fileHeader.data()), FILE_HEADER_SIZE);

        // Write info header
        std::array<unsigned char, INFO_HEADER_SIZE> infoHeader 
            = createInfoHeader(height, width);
        ofs.write(reinterpret_cast<char*>(infoHeader.data()), INFO_HEADER_SIZE);

        // Write pixel array
        for (int i = height - 1; i >= 0; i--) {
            for (int j = 0; j < width; j++) {
                // Write B, G, R values
                ofs.put(img[i][j].b);
                ofs.put(img[i][j].g);
                ofs.put(img[i][j].r);
            }

            // Write padding
            for (int k = 0; k < paddingSize; k++) {
                ofs.put(0);
            }
        }

        ofs.close();
    }

    std::array<unsigned char, FILE_HEADER_SIZE> createFileHeader(
        int height, 
        int stride
    ) {
        const int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE 
                             + (stride * height);

        std::array<unsigned char, FILE_HEADER_SIZE> fileHeader = {
            0,0,      // signature (always "BM")
            0,0,0,0,  // image file size in bytes
            0,0,0,0,  // reserved (always 0)
            0,0,0,0   // offset to pixel array
        };

        fileHeader[0]  = 'B';
        fileHeader[1]  = 'M';
        fileHeader[2]  = static_cast<unsigned char>(fileSize      );
        fileHeader[3]  = static_cast<unsigned char>(fileSize >>  8);
        fileHeader[4]  = static_cast<unsigned char>(fileSize >> 16);
        fileHeader[5]  = static_cast<unsigned char>(fileSize >> 24);
        fileHeader[10] = static_cast<unsigned char>(FILE_HEADER_SIZE
                                                    + INFO_HEADER_SIZE);

        return fileHeader;
    }

    std::array<unsigned char, INFO_HEADER_SIZE> createInfoHeader(
        int height,
        int width
    ) {
        std::array<unsigned char, INFO_HEADER_SIZE> infoHeader = {
            0,0,0,0,  // header size
            0,0,0,0,  // image width
            0,0,0,0,  // image height
            0,0,      // number of color planes
            0,0,      // bits per pixel
            0,0,0,0,  // compression
            0,0,0,0,  // image size
            0,0,0,0,  // horizontal resolution
            0,0,0,0,  // vertical resolution
            0,0,0,0,  // colors in color table
            0,0,0,0   // important color count
        };

        infoHeader[0]  = static_cast<unsigned char>(INFO_HEADER_SIZE);
        infoHeader[4]  = static_cast<unsigned char>(width      );
        infoHeader[5]  = static_cast<unsigned char>(width >>  8);
        infoHeader[6]  = static_cast<unsigned char>(width >> 16);
        infoHeader[7]  = static_cast<unsigned char>(width >> 24);
        infoHeader[8]  = static_cast<unsigned char>(height      );
        infoHeader[9]  = static_cast<unsigned char>(height >>  8);
        infoHeader[10] = static_cast<unsigned char>(height >> 16);
        infoHeader[11] = static_cast<unsigned char>(height >> 24);
        infoHeader[12] = static_cast<unsigned char>(1);
        infoHeader[14] = static_cast<unsigned char>(BYTES_PER_PIXEL*8);

        return infoHeader;
    }
}