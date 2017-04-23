#include "include/Engine.h"

namespace vlp {
	Engine::Engine() :
		m_running(false) {
	}

	Engine::~Engine() {
	}

	void Engine::initialize() {
		m_threadPool.initialize(*this);
		m_running = true;
	}

	bool Engine::isRunning() noexcept {
		return m_running;
	}

	ThreadPool& Engine::getThreadPool() {
		return m_threadPool;
	}

	ResourceCache& Engine::getResourceCache() {
		return m_resourceCache;
	}

	ResourceLoader& Engine::getResourceLoader() {
		return m_resourceLoader;
	}
}