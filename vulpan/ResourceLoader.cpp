#include <fstream>
#include "include/DDSParser.h"
#include "include/Logger.h"
#include "include/ResourceLoader.h"

namespace vlp {
	ResourceLoader::ResourceLoader() {
		m_textureParsers["dds"] = new DDSParser();
	}

	ResourceLoader::~ResourceLoader() {
		for (auto& parser : m_textureParsers) {
			delete parser.second;
		}
	}

	const TextureResource ResourceLoader::loadDDS(const std::vector<uint8_t>& data) {
		return m_textureParsers["dds"]->parse(data);
	}

	std::vector<uint8_t> ResourceLoader::readFile(const std::string& path) {
		std::ifstream file(path, std::ios::binary);
		if (!file) {
			logger.log("Unable to open file '%s'", path.c_str());
			return std::vector<uint8_t>();
		}

		std::vector<uint8_t> data;
		const size_t chunkSize = 4096;
		uint8_t buffer[chunkSize];

		while (!file.eof()) {
			file.read(reinterpret_cast<char*>(buffer), chunkSize);

			auto bytesRead = file.gcount();
			if (bytesRead < chunkSize) {
				data.insert(data.end(), buffer, buffer + bytesRead);
				break;
			}

			data.insert(data.end(), buffer, buffer + chunkSize);
		}
		file.close();

		return data;
	}
}