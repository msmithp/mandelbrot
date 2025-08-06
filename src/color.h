#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <vector>

namespace color {
    struct Color {
        uint8_t r, g, b;
    };

    const Color BLACK = {0, 0, 0};
    const Color WHITE = {255, 255, 255};
    const std::vector<Color> BLUE_ORANGE = {
        {28, 43, 153}, {44, 97, 201}, {241, 247, 208},
        {255, 194, 26}, {255, 5, 5}
    };
    const std::vector<Color> SUNSET = {
        {45, 99, 169}, {133, 49, 196}, {255, 232, 201},
        {250, 182, 55}, {214, 46, 91}
    };

    /**
     * @brief Sample a color between two other colors
     * 
     * @param start First color of gradient
     * @param end Second color of gradient
     * @param pct Value between 0 and 1 representing how far from the first
     *            color the sample will be, with 0 being equivalent to the
     *            starting color and 1 being equivalent to the ending color
     * @return Sampled color
     */
    Color linearGradient(Color start, Color end, double pct);

    /**
     * @brief Sample a color between many other colors
     * 
     * @param colors Colors that form individual linear gradients
     * @param pct Value between 0 and 1 representing how far from the first
     *            color the sample will be, with 0 being equivalent to the
     *            first color in `colors` and 1 being equivalent to the
     *            last color in `colors`
     * @return Sampled color
     */
    Color polylinearGradient(const std::vector<Color> colors, double pct);
}

#endif