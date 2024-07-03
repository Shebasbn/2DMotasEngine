#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
    public:
        static void Log(const std::string& messages);
        static void Error(const std::string& messages);
};

#endif
