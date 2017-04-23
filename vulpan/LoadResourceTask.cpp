#include "include/Engine.h"
#include "include/LoadResourceTask.h"
#include "include/Logger.h"

namespace vlp {
	LoadResourceTask::LoadResourceTask(std::string&& path) :
		m_path(std::move(path)) {
	}

	void LoadResourceTask::run(Engine& engine) {
		auto loader = engine.getResourceLoader();
		auto data = loader.readFile(m_path);

		if (data.size() == 0) {
			// readFile will log the exact error
			logger.log("Unable to load resource '%s'", m_path.c_str());
			return;
		}

		if (data.size() >= 128 && memcmp(data.data(), "DDS ", 4) == 0) {
			auto resource = loader.loadDDS(data);
			engine.getResourceCache().add<TextureResource>(m_path, resource);
		}
		else {
			logger.log("Resource '%s' is in an unsupported format", m_path.c_str());
		}
	}
}