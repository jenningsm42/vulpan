#include "include/DDSParser.h"
#include "include/Logger.h"

namespace vlp {
	struct DDSPixelFormat {
		uint32_t size;
		uint32_t flags;
		uint32_t fourCC;
		uint32_t pixelBitCount;
		uint32_t redBitMask;
		uint32_t greenBitMask;
		uint32_t blueBitMask;
		uint32_t alphaBitMask;
	};

	struct DDSHeader {
		uint32_t       size;
		uint32_t       flags;
		uint32_t       height;
		uint32_t       width;
		uint32_t       pitchOrLinearSize;
		uint32_t       depth;
		uint32_t       mipMapCount;
		uint32_t       reserved[11];
		DDSPixelFormat format;
		uint32_t       caps;
		uint32_t       caps2;
		uint32_t       caps3;
		uint32_t       caps4;
		uint32_t       reserved2;
	};

	const TextureResource DDSParser::parse(const std::vector<uint8_t>& data) {
		if (data.size() < 128) {
			logger.log("No header found in DDS texture");
			return TextureResource();
		}

		auto buffer = data.data();
		if (memcmp(buffer, "DDS ", 4) != 0) {
			logger.log("Invalid header in DDS texture");
			return TextureResource();
		}

		DDSHeader header;
		memcpy(&header, buffer + 4, sizeof(DDSHeader));

		if (header.size != 124) {
			logger.log("Invalid header size in DDS texture (must be 124)");
			return TextureResource();
		}

		if (header.width == 0 || header.height == 0) {
			logger.log("Empty image in DDS texture");
			return TextureResource();
		}

		TextureResource resource;
		resource.width = header.width;
		resource.height = header.height;
		resource.mipMapCount = header.mipMapCount;

		// TODO: Finish loading actual pixel data

		resource.loaded = true;
		return resource;
	}
}