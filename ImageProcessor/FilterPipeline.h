#pragma once

#include "FilterBase.h"

#include <memory>
#include <vector>

namespace ip {

class FilterPipeline {

public:
	// 필터 추가
	void add(std::unique_ptr<FilterBase> filter);

	void apply(ImageBuffer& image);


private:
	std::vector<std::unique_ptr< FilterBase>> m_filters; 

};

}  //namespace ip


