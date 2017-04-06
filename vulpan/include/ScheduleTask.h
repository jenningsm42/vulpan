#pragma once
#include "Task.h"

namespace vlp {
	class ScheduleTask : public Task {
	public:
		void run(Engine& engine);
	};
}