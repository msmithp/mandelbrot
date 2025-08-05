#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <vector>

namespace color {
    struct Color {
        uint8_t r, g, b;
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
    Color polylinearGradient(std::vector<Color> colors, double pct);
}

#endif