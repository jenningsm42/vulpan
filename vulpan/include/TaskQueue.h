#pragma once
#include <memory>
#include <mutex>
#include <queue>
#include "Task.h"

namespace vlp {
	class TaskQueue {
	public:
		TaskQueue();
		~TaskQueue();

		// Thread-safe enqueue with rvalue
		template <typename T, typename... Args>
		void enqueue(Args&&... args) {
			std::lock_guard<std::mutex> lock(m_mutex);
			m_queue.emplace(std::make_shared<T>(std::forward<Args>(args)...));
		}
		
		// Thread-safe dequeue
		std::shared_ptr<Task> dequeue();

	private:
		std::queue<std::shared_ptr<Task>> m_queue;
		std::mutex m_mutex;
	};
}