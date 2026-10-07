#include "ThresholdFilter.h"

namespace ip {

    ThresholdFilter::ThresholdFilter(int threshold)
        : m_threshold(threshold)
    { }

    void ThresholdFilter::apply(ImageBuffer& image) {
        for (int y = 0; y < image.height(); y++) {
            std::uint8_t* row = image.rowPtr(y);

            for (int x = 0; x < image.width(); x++) {
                std::uint8_t* pixel = row + x * ImageBuffer::CHANNELS;

                // 현재 픽셀의 B, G, R 값을 가져온다.
                const int b = pixel[0];
                const int g = pixel[1];
                const int r = pixel[2];

                // B, G, R을 이용해서 밝기값을 계산한다.
                const int gray = static_cast<int>(
                        0.114 * b +
                        0.587 * g +
                        0.299 * r
                        );

                int value;

                // 밝기값이 임계값보다 크면 흰색
                if (gray > m_threshold) {
                    value = 255;
                }
                // 밝기값이 임계값보다 작거나 같으면 검정색
                else {
                    value = 0;
                }

                // B, G, R에 같은 값을 저장해서 흑백으로 만든다.
                pixel[0] = static_cast<std::uint8_t>(value);

                pixel[1] = static_cast<std::uint8_t>(value);

                pixel[2] = static_cast<std::uint8_t>(value);
            }
        }
    }

} // namespace ip