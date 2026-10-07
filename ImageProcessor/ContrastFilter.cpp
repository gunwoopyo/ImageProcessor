#include "ContrastFilter.h"

namespace ip {

    ContrastFilter::ContrastFilter(int contrast)
        : m_contrast(contrast)
    { }

    void ContrastFilter::apply(ImageBuffer& image) {
        for (int y = 0; y < image.height(); y++) {
            std::uint8_t* row = image.rowPtr(y);

            for (int x = 0; x < image.width(); x++) {
                std::uint8_t* pixel = row + x * ImageBuffer::CHANNELS;

                int b = static_cast<int>(pixel[0]);
                int g = static_cast<int>(pixel[1]);
                int r = static_cast<int>(pixel[2]);

                b = static_cast<int>((b - 128) * m_contrast / 100.0 + 128);
                g = static_cast<int>((g - 128) * m_contrast / 100.0 + 128);
                r = static_cast<int>((r - 128) * m_contrast / 100.0 + 128);

                if (b < 0) b = 0;
                if (b > 255) b = 255;

                if (g < 0) g = 0;
                if (g > 255) g = 255;

                if (r < 0) r = 0;
                if (r > 255) r = 255;

                pixel[0] = static_cast<std::uint8_t>(b);
                pixel[1] = static_cast<std::uint8_t>(g);
                pixel[2] = static_cast<std::uint8_t>(r);
            }
        }
    }

} // namespace ip