#pragma once

#include "ImageBuffer.h"

namespace ip {

class FilterBase {

public:
	virtual ~FilterBase() = default;

	// 가상 함수
	virtual void apply(ImageBuffer& image) = 0;


};

}  // namespace ip
