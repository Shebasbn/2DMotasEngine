#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <string>

struct LogEntry {
    uint32_t type;
    std::string message;
};

class Logger {
    public:
        static std::vector<LogEntry> messages;
        static void Log(const std::string& messages);
        static void Error(const std::string& messages);
};

#endif
