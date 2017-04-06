#include "include/ScheduleTask.h"
#include "include/Engine.h"
#include "include/LogTask.h"

namespace vlp {
	void ScheduleTask::run(Engine& engine) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		engine.getThreadPool().addTask<LogTask>("hello!");
		engine.getThreadPool().addTask<ScheduleTask>();
	}
}