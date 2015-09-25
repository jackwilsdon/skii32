#ifndef _LOG_DESTINATION_H_
#define _LOG_DESTINATION_H_

#include <string>

#include "logger/log_level.h"
#include "logger/export.h"

class Logger;

class LOGGER_EXPORT LogDestination {
public:
    LogDestination(Logger *logger);
    LogDestination(const LogDestination &destination);
    virtual ~LogDestination();

    Logger *get_logger() const;
    virtual void log(LogLevel level, std::string message) const = 0;

private:
    Logger *logger;
};

#endif
