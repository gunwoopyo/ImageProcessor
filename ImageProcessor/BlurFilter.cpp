#include "BlurFilter.h"

#include <cstdint>

namespace ip {

    void BlurFilter::apply(ImageBuffer& image) {
        // 원본과 같은 크기의 결과 이미지 생성
        ImageBuffer result(
            image.width(),
            image.height()
        );

        for (int y = 0; y < image.height(); y++) {
            for (int x = 0; x < image.width(); x++) {
                int sumB = 0;
                int sumG = 0;
                int sumR = 0;

                int count = 0;

    
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        int nx = x + dx;
                        int ny = y + dy;

                        if (nx < 0 ||  nx >= image.width() || ny < 0 || ny >= image.height()) 
                            continue;
                        

                        const std::uint8_t* pixel = image.rowPtr(ny) + nx * ImageBuffer::CHANNELS;

                        sumB += pixel[0];
                        sumG += pixel[1];
                        sumR += pixel[2];

                        count++;
                    }
                }

                std::uint8_t* resultPixel = result.rowPtr(y) + x * ImageBuffer::CHANNELS;

                resultPixel[0] = static_cast<std::uint8_t>(sumB / count);

                resultPixel[1] = static_cast<std::uint8_t>(sumG / count);

                resultPixel[2] = static_cast<std::uint8_t>(sumR / count);
            }
        }


        image = std::move(result);
    }

} // namespace ip