#pragma once

#include "FilterBase.h"

namespace ip {

class ContrastFilter : public FilterBase{

public:
    explicit ContrastFilter(int contrast);

    void apply(ImageBuffer& image) override;

private:
    int m_contrast;

};

}

