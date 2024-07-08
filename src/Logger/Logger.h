#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>

namespace MotasEngine {
typedef std::string LogMessage;

enum LogType { LOG_INFO, LOG_WARNING, LOG_ERROR };

struct LogEntry {
  LogType type;
  LogMessage message;
};

typedef std::vector<LogEntry> LogBook;

class Logger {
public:
  static LogBook logBook;
  static void Log(const LogMessage &messages);
  static void Warn(const LogMessage &messages);
  static void Error(const LogMessage &messages);
};
} // namespace MotasEngine

#endif
