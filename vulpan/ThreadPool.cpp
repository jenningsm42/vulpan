#include "include/ThreadPool.h"
#include "include/ScheduleTask.h"

namespace vlp {
	ThreadPool::ThreadPool() {
	}

	ThreadPool::~ThreadPool() {
		for (auto& thread : m_threads) {
			thread.stop();
		}
	}

	void ThreadPool::initialize(Engine& engine, unsigned int numThreads) {
		if (numThreads <= 0) {
			unsigned int availableThreads = std::thread::hardware_concurrency();
			numThreads = availableThreads > 1 ? availableThreads - 1 : 1;
		}

		for (unsigned i = 0; i < numThreads; i++) {
			m_threads.emplace_back(Thread(engine, &m_taskQueue));
		}

		addTask<ScheduleTask>();

		for (auto& thread : m_threads) {
			thread.start();
		}
	}
}