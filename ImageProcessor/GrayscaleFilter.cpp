#include "GrayscaleFilter.h"

namespace ip {

    void GrayscaleFilter::apply(ImageBuffer& image) {

        for (int y = 0; y < image.height(); y++) {

            std::uint8_t* row = image.rowPtr(y);

            for (int x = 0; x < image.width(); x++) {
               
                std::uint8_t* pixel = row + x * ImageBuffer::CHANNELS;

               
                const std::uint8_t b = pixel[0];
                const std::uint8_t g = pixel[1];
                const std::uint8_t r = pixel[2];

                
                const int gray = static_cast<int>(
                        0.114 * b +
                        0.587 * g +
                        0.299 * r
                        );

                
                pixel[0] = static_cast<std::uint8_t>(gray);
                pixel[1] = static_cast<std::uint8_t>(gray);
                pixel[2] = static_cast<std::uint8_t>(gray);
            }
        }


    }

} // namespace ip