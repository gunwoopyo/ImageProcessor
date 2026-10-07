#pragma once

#include "FilterBase.h"

namespace ip {

class ThresholdFilter : public FilterBase {
public:
    ThresholdFilter(int threshold);

    void apply(ImageBuffer& image) override;

private:
    int m_threshold;
};

} // namespace ip