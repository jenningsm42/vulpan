#include <thread>
#include "include/WaitTask.h"

namespace vlp {
	void WaitTask::run(Engine& engine) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}