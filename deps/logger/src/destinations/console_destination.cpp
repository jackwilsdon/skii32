#include "logger/destinations/console_destination.h"

#if defined(__APPLE__) || defined(__linux)
#define __CONSOLE_COLOR_SUPPORTED
#endif

namespace logger {
    ConsoleDestination::ConsoleDestination(Logger &logger) : Destination(logger) {

    }

    ConsoleDestination::~ConsoleDestination() { }

    void ConsoleDestination::log(Level level, std::string message) {
        printf("[%s] %s\n", GetLevelName(level, true).c_str(), message.c_str());
    }

    Destination* ConsoleDestination::clone() const {
        return new ConsoleDestination(getLogger());
    }
}
