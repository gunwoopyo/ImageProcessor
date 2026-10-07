#include "FlipFilter.h"

#include <algorithm>

namespace ip {

    FlipFilter::FlipFilter(Direction direction)
        : m_direction(direction)
    { }

    void FlipFilter::apply(ImageBuffer& image) {
        if (m_direction == Direction::Horizontal) {
            // 좌우 반전
            for (int y = 0; y < image.height(); y++) {
                std::uint8_t* row = image.rowPtr(y);

                for (int x = 0; x < image.width() / 2; x++) {
                    std::uint8_t* left = row + x * ImageBuffer::CHANNELS;

                    std::uint8_t* right = row + (image.width() - 1 - x) * ImageBuffer::CHANNELS;

                    for (int channel = 0; channel < ImageBuffer::CHANNELS; channel++) {
                        std::swap(left[channel],
                            right[channel]);
                    }
                }
            }
        }
        else {
            // 상하 반전
            for (int y = 0; y < image.height() / 2; y++) {
                std::uint8_t* top = image.rowPtr(y);

                std::uint8_t* bottom = image.rowPtr(image.height() - 1 - y);

                for (int x = 0; x < image.rowStride();x++) {
                    std::swap(top[x], bottom[x]);
                }
            }
        }
    }

} // namespace ip