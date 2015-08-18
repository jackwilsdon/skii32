#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>
#include <cstdarg>

#include "logger/log_level.h"

#include "platform/platform.h"

class LogDestination;

class EXPORT Logger {
public:
    Logger();
    Logger(const Logger &logger);
    ~Logger();

    LogDestination *get_destination() const;
    void set_destination(LogDestination *destination, bool delete_destination = false);

    LogLevel get_level() const;
    void set_level(LogLevel level);

    void vlog(LogLevel level, std::string format, va_list args) const;
    void log(LogLevel level, std::string format, ...) const;

    void vlog(std::string format, va_list args) const;
    void log(std::string format, ...) const;

private:
    LogDestination *destination;
    bool delete_destination;

    LogLevel level;
};

#endif
