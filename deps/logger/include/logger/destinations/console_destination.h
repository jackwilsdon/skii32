#ifndef CONSOLE_DESTINATION_H
#define CONSOLE_DESTINATION_H

#include "logger/destination.h"

namespace logger {
    class LOGGER_EXPORT ConsoleDestination : public Destination {
    public:
        ConsoleDestination(Logger& logger);
        ConsoleDestination(const ConsoleDestination &destination);
        ~ConsoleDestination();

        void log(Level level, std::string message);
    };
}

#endif
