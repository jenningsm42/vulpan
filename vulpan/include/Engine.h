#pragma once
#include <memory>
#include "ThreadPool.h"

namespace vlp {
	class Engine {
	public:
		Engine();
		~Engine();

		void initialize();

		bool isRunning() noexcept;

		ThreadPool& getThreadPool();

	private:
		ThreadPool m_threadPool;
		bool m_running;
	};
}