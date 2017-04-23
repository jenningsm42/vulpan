#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include "TextureResource.h"

namespace vlp {
	class TextureParser;

	class ResourceLoader {
	public:
		ResourceLoader();
		~ResourceLoader();

		const TextureResource loadDDS(const std::vector<uint8_t>&);

		std::vector<uint8_t> readFile(const std::string& path);

	private:
		std::unordered_map<std::string, TextureParser*> m_textureParsers;
	};
}