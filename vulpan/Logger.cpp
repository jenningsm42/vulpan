#include "Logger.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdarg>
#include <mutex>

Logger logger("vulpes.log");

Logger::Logger(const std::string& file) : m_fileName(file) {
}

Logger::~Logger() {
	std::lock_guard<std::mutex> lock(m_mutex);
}

void Logger::log(const std::string& log, ...) {
	std::lock_guard<std::mutex> lock(m_mutex);

	// Get arguments
	va_list args;
	va_start(args, &log);

	// Get time
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	char timestr[64];
	strftime(timestr, 64, "%H:%M:%S", timeinfo);

	// Parse log with time and arguments
	char logWithTime[4096], finalLog[4096];
	sprintf(logWithTime, "[%s] %s", timestr, log.c_str());
	vsprintf(finalLog, logWithTime, args);

	// Write to stdout
	std::cout << finalLog << std::endl;

	// Write to given file
	std::ofstream o;
	o.open(m_fileName, std::ofstream::out | std::ofstream::app);
	o << finalLog << std::endl;
	o.close();
}