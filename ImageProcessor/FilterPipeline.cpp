#include "FilterPipeline.h"

#include <stdexcept>
#include <utility>

namespace ip {

void FilterPipeline::add(std::unique_ptr<FilterBase> filter) {

	if (!filter) {
		throw std::invalid_argument(
			"FilterPipeline: null filter"
		);
	}

	m_filters.push_back(std::move(filter));
}

void FilterPipeline::apply(ImageBuffer& image) {
	
	for (auto& filter : m_filters) {
		filter->apply(image);
	}
}

} //namespace ip
