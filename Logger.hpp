#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <string>
#include <shared_mutex>

class Logger {
public:
    Logger(const std::string& filename);
    ~Logger();

    void log(const std::string& message);
    std::string read_line();

private:
    std::fstream file_;
    std::shared_mutex mutex_;
};

#endif // LOGGER_HPP
