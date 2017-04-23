#include "include/Logger.h"

Logger logger("vulpes.log");

Logger::Logger(std::string&& file) : m_fileName(std::move(file)) {
}

Logger::~Logger() {
	std::lock_guard<std::mutex> lock(m_mutex);
}