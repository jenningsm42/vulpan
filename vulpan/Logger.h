#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <string>

class Logger {
public:
	Logger(std::string&& file);
	~Logger();

	// Log given message to stdout and to specified file
	template <typename... Args>
	void log(std::string&& formattedLog, Args&&... args) {
		std::lock_guard<std::mutex> lock(m_mutex);

		// Get the current time
		auto time = std::chrono::system_clock::to_time_t(
			std::chrono::system_clock::now());

		char timeString[64];
		if (std::strftime(timeString, sizeof(timeString), "%H:%M:%S", std::localtime(&time))) {
			formattedLog = "[" + std::string(timeString) + "] " + formattedLog;
		}

		// Parse log
		char log[4096];
		sprintf(log, formattedLog.c_str(), args...);

		// Write to stdout
		std::cout << log << std::endl;

		// Write to file
		std::ofstream o;
		o.open(m_fileName, std::ofstream::out | std::ofstream::app);
		o << log << std::endl;
		o.close();
	}

private:
	std::mutex m_mutex;
	std::string m_fileName;
};

// Main internal logger
extern Logger logger;