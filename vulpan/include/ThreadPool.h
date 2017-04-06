#pragma once
#include <vector>
#include "Task.h"
#include "TaskQueue.h"
#include "Thread.h"

namespace vlp {
	class ThreadPool {
	public:
		ThreadPool();
		~ThreadPool();

		void initialize(Engine& engine, unsigned int numThreads = 0);

		template <typename T, typename... Args>
		void addTask(Args&&... args) {
			m_taskQueue.enqueue<T>(std::forward<Args>(args)...);
		}

	private:
		std::vector<Thread> m_threads;
		TaskQueue m_taskQueue;
	};
}
