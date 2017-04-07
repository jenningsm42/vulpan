#include "Logger.h"

Logger logger("vulpes.log");

Logger::Logger(const std::string& file) : m_fileName(file) {
}

Logger::~Logger() {
	std::lock_guard<std::mutex> lock(m_mutex);
}