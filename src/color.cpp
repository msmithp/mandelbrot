#include "color.h"
#include <cmath>
#include <vector>

namespace color {
    struct Color;

    Color linearGradient(Color start, Color end, double pct) {
        // Cast RGB values to ints, since values can become negative during
        // calculations
        const int r1 = static_cast<int>(start.r);
        const int g1 = static_cast<int>(start.g);
        const int b1 = static_cast<int>(start.b);

        const int r2 = static_cast<int>(end.r);
        const int g2 = static_cast<int>(end.g);
        const int b2 = static_cast<int>(end.b);

        /*
        To get the RGB values of the desired point between the two colors, we
        think of the RGB values as vectors in 3D space and use the following
        equation:
                    [ r1 ]   / [ r2 ]   [ r1 ] \         [ r3 ] 
                    [ g1 ] + | [ g2 ] - [ g1 ] | * pct = [ g3 ]
                    [ g1 ]   \ [ b2 ]   [ b1 ] /         [ b3 ]
        */
        const int r3 = r1 + static_cast<int>(std::round((r2 - r1) * pct));
        const int g3 = g1 + static_cast<int>(std::round((g2 - g1) * pct));
        const int b3 = b1 + static_cast<int>(std::round((b2 - b1) * pct));

        return {
            static_cast<int>(r3),
            static_cast<int>(g3),
            static_cast<int>(b3)
        };
    }

    Color polylinearGradient(std::vector<Color> colors, double pct) {
        if (colors.size() == 1) {
            return colors[0];
        } else if (colors.size() == 2) {
            return linearGradient(colors[0], colors[1], pct);
        }

        const double threshold = 1.0 / (colors.size() - 1);
        const int startIndex = std::min(
            static_cast<int>(std::floor(pct / threshold)),
            static_cast<int>(colors.size() - 2)
        );
        const int endIndex = startIndex + 1;

        return linearGradient(
            colors[startIndex],
            colors[endIndex],
            (pct / threshold) - startIndex
        );
    }
}