#ifndef _CONSOLE_DESTINATION_H_
#define _CONSOLE_DESTINATION_H_

#include <string>

#include "logger/platform.h"
#include "logger/log_destination.h"
#include "logger/log_level.h"

class Logger;

class EXPORT ConsoleDestination : public LogDestination {
public:
    ConsoleDestination(Logger *logger);

    bool is_colored();
    void set_colored(bool colored);

    void log(LogLevel level, std::string message);

private:
    bool colored;
};

#endif
