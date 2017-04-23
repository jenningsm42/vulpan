#pragma once
#include <string>
#include "Task.h"

namespace vlp {
	class LogTask : public Task {
	public:
		LogTask(std::string&&);

		void run(Engine& engine) override;

	private:
		std::string m_message;

		// TODO: Render string using variadic args, also update actual logger
	};
}