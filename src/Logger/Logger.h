#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <string>

typedef std::string LogMessage;

enum LogType {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
};

struct LogEntry {
    LogType type;
    LogMessage message;
};

typedef std::vector<LogEntry> LogBook;

class Logger {
    public:
        static LogBook logBook;
        static void Log(const LogMessage& message);
        static void Warn(const LogMessage& message);
        static void Error(const LogMessage& message);
};

#endif
