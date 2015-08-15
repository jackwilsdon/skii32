#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>
#include <cstdarg>

#include "logger/platform.h"
#include "logger/log_level.h"

class LogDestination;

class EXPORT Logger {
public:
    Logger();
    ~Logger();

    LogDestination *get_destination();
    void set_destination(LogDestination *destination, bool delete_destination = false);

    LogLevel get_level();
    void set_level(LogLevel level);

    void vlog(LogLevel level, std::string format, va_list args);
    void log(LogLevel level, std::string format, ...);

    void vlog(std::string format, va_list args);
    void log(std::string format, ...);

private:
    LogDestination *destination;
    bool delete_destination;

    LogLevel level;
};

#endif
