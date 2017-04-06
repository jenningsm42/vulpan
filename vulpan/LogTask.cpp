#include "include/LogTask.h"
#include "Logger.h"

namespace vlp {
	LogTask::LogTask(std::string&& message) : m_message(std::move(message)) {
	}

	void LogTask::run(Engine& engine) {
		logger.log(m_message);
	}
}