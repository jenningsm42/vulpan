#pragma once
#include "TextureParser.h" 

namespace vlp {
	class DDSParser : public TextureParser {
	public:
		const TextureResource parse(const std::vector<uint8_t>&) override;
	};
}