#include "Logger.h"
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

// TODO: Not working try again
LogBook Logger::logBook;
LogMessage CurrentDateTimeToString() {
    time_t t;
    struct tm *tmp;
    char date[30];
    time(&t);
    tmp = localtime(&t);
    std::strftime(date, sizeof(date), "%d-%b-%y %H:%M:%S", tmp);
    LogMessage output(date);
    return output;
}

void Logger::Log(const LogMessage& message) {
    LogEntry entry;
    entry.type = LOG_INFO;
    entry.message = "LOG: [" + CurrentDateTimeToString() + "]: " + message;
    std::cout << "\x1B[32m" << entry.message << "\033[0m" << std::endl;
    logBook.push_back(entry);
}

void Logger::Warn(const LogMessage& message) {
    LogEntry entry;
    entry.type = LOG_WARNING;
    entry.message = "WARNNING: [" + CurrentDateTimeToString() + "]: " + message;
    std::cout << "\x1B[32m" << entry.message << "\033[0m" << std::endl;
    logBook.push_back(entry);
}

void Logger::Error(const LogMessage& message) {
    LogEntry entry;
    entry.type = LOG_ERROR;
    entry.message = "ERROR: [" + CurrentDateTimeToString() + "]: " + message;
    std::cerr << "\x1B[91m"<< entry.message << "\033[0m" << std::endl;
    logBook.push_back(entry);
}
