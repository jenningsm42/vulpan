#pragma once
#include <thread>
#include "Task.h"

namespace vlp {
	class Engine;
	class TaskQueue;

	class Thread {
	public:
		Thread(Engine& engine, TaskQueue* taskQueue);
		Thread(Thread&&);
		~Thread();

		void start();
		void stop();

	private:
		std::thread m_thread;
		Engine& m_engine;
		TaskQueue* m_taskQueue;
		bool m_running;
		bool m_threadDone;

		void run();
	};
}
