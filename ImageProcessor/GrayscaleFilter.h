#pragma once



#include "FilterBase.h"

namespace ip {

	class GrayscaleFilter : public FilterBase {

	public:

		void apply(ImageBuffer& image) override;
	};


} // namespace ip 


