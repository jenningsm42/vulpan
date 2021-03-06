#include "include/LogTask.h"
#include "include/Logger.h"

namespace vlp {
	LogTask::LogTask(std::string&& message) : m_message(std::move(message)) {
	}

	void LogTask::run(Engine& engine) {
		logger.log(std::move(m_message));
	}
}