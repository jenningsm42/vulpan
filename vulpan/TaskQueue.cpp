#include "include/TaskQueue.h"
#include "include/WaitTask.h"

namespace vlp {
	TaskQueue::TaskQueue() {
	}

	TaskQueue::~TaskQueue() {
		std::lock_guard<std::mutex> lock(m_mutex);
	}

	std::shared_ptr<Task> TaskQueue::dequeue() {
		std::lock_guard<std::mutex> lock(m_mutex);

		// Wait for more tasks
		if (m_queue.empty()) {
			return std::make_shared<WaitTask>();
		}

		auto task = m_queue.front();
		m_queue.pop();
		return task;
	}
}