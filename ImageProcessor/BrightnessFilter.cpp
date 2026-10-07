#include "BrightnessFilter.h"

namespace ip {

    BrightnessFilter::BrightnessFilter(int bright)
        : m_brightness(bright)
    { }

    void BrightnessFilter::apply(ImageBuffer& image) {
        for (int y = 0; y < image.height(); y++) {

            std::uint8_t* row = image.rowPtr(y);

            for (int x = 0; x < image.width(); x++) {
                std::uint8_t* pixel = row + x * ImageBuffer::CHANNELS;

                int b = static_cast<int>(pixel[0]) + m_brightness;

                int g = static_cast<int>(pixel[1]) + m_brightness;

                int r = static_cast<int>(pixel[2]) + m_brightness;

                pixel[0] = static_cast<std::uint8_t>(clamp(b));

                pixel[1] = static_cast<std::uint8_t>(clamp(g));

                pixel[2] = static_cast<std::uint8_t>(clamp(r));

            }
        }
    }

    int BrightnessFilter::clamp(int value) {
        if (value < 0)
            return 0;

        else if (value > 255)
            return 255;

        else
            return value;
    }

} // namespace ip