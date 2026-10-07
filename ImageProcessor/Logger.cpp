#include "Logger.h"

namespace ip {

Logger::Logger() {
	m_file.open(
		"ImageProcessor.log",
		std::ios::app
		);
}

Logger::~Logger() {
	m_file.close();
}

void Logger::success(const std::string& command) {
	

	m_file << "[SUCCESS]\n";
}

void Logger::failure(const std::string& command) {
	m_file << "FAILURE\n";
}

} // namespace ip
