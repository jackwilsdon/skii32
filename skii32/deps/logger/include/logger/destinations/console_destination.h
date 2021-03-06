#ifndef _CONSOLE_DESTINATION_H_
#define _CONSOLE_DESTINATION_H_

#include <string>

#include "logger/log_destination.h"
#include "logger/log_level.h"
#include "logger/export.h"

class Logger;

class LOGGER_EXPORT ConsoleDestination : public LogDestination {
public:
    ConsoleDestination(Logger *logger);
    ConsoleDestination(const ConsoleDestination &destination);

    bool is_colored() const;
    void set_colored(bool colored);

    void auto_set_colored();

    void log(LogLevel level, std::string message) const;

private:
    bool colored;
};

#endif
