#pragma once

#include "FilterBase.h"

namespace ip {

class BrightnessFilter : public FilterBase {
public:
    BrightnessFilter(int bright);
    
    static int clamp(int value);

    void apply(ImageBuffer& image) override;


private:
    int m_brightness = 0;


};

} // namespace ip