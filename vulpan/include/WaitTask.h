#pragma once
#include "Task.h"

namespace vlp {
	class WaitTask : public Task {
	public:
		void run(Engine& engine) override;
	};
}