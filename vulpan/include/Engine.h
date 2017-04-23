#pragma once
#include <memory>
#include "ResourceCache.h"
#include "ResourceLoader.h"
#include "ThreadPool.h"

namespace vlp {
	class Engine {
	public:
		Engine();
		~Engine();

		void initialize();

		bool isRunning() noexcept;

		ThreadPool& getThreadPool();
		ResourceCache& getResourceCache();
		ResourceLoader& getResourceLoader();

	private:
		ResourceCache m_resourceCache;
		ResourceLoader m_resourceLoader;
		ThreadPool m_threadPool;
		bool m_running;
	};
}