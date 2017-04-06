#pragma once
#include <string>
#include <mutex>

class Logger {
public:
	Logger(const std::string& file);
	~Logger();

	// Log given message to stdout and to specified file
	void log(const std::string& log, ...);

private:
	std::mutex m_mutex;
	std::string m_fileName;
};

// Main internal logger
extern Logger logger;