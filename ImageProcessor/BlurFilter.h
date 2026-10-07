#pragma once

#include "FilterBase.h"

namespace ip {

class BlurFilter : public FilterBase {
public:
	void apply(ImageBuffer& image) override;

};


}  // namespace ip





