#include "Logger.hpp"
#include <iostream>

Logger::Logger(const std::string& filename) {
    file_.open(filename, std::ios::in | std::ios::out | std::ios::app);
    if (!file_.is_open()) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
    }
}

Logger::~Logger() {
    if (file_.is_open()) {
        file_.close();
    }
}

void Logger::log(const std::string& message) {
    std::unique_lock lock(mutex_);
    if (file_.is_open()) {
        file_ << message << std::endl;
    }
}

std::string Logger::read_line() {
    std::shared_lock lock(mutex_);
    std::string line;
    
    if (file_.is_open() && std::getline(file_, line)) {
        return line;
    }
    
    return "";
}
