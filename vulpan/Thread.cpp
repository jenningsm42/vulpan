#include "include/Thread.h"
#include "include/ThreadPool.h"
#include "include/Logger.h"

namespace vlp {
	Thread::Thread(Engine& engine, TaskQueue* taskQueue) :
		m_engine(engine),
		m_taskQueue(taskQueue),
		m_running(false),
		m_threadDone(true) {
	}

	Thread::Thread(Thread&& other) :
		m_thread(std::move(other.m_thread)),
		m_engine(std::move(other.m_engine)),
		m_taskQueue(std::move(other.m_taskQueue)),
		m_running(std::move(other.m_running)),
		m_threadDone(std::move(other.m_threadDone)) {
	}

	Thread::~Thread() {
		m_running = false;
		while (!m_threadDone) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}

	void Thread::start() {
		m_running = true;
		m_thread = std::thread(&Thread::run, this);
		m_thread.detach();
	}

	void Thread::stop() {
		m_running = false;
	}

	void Thread::run() {
		logger.log("Thread %d running", std::this_thread::get_id());
		m_threadDone = false;
		while (m_running) {
			auto task = m_taskQueue->dequeue();
			task->run(m_engine);
		}
		logger.log("Thread %d exited", std::this_thread::get_id());
		m_threadDone = true;
	}
}