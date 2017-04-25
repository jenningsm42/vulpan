#pragma once
#include "Resource.h"

namespace vlp {
	struct TextureResource : public Resource {
		size_t getType() const noexcept {
			return typeid(TextureResource).hash_code();
		}
		uint32_t width = 0;
		uint32_t height = 0;
		uint32_t mipMapCount = 0;
		uint32_t* pixels = nullptr;
		uint32_t format = 0;
	};
}