#pragma once
#include <vector>
#include "TextureResource.h"

namespace vlp {
	class TextureParser {
	public:
		virtual const TextureResource parse(const std::vector<uint8_t>&) = 0;
	};
}