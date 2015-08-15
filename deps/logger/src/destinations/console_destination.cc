#include <time.h>
#include <cstdio>

#include "logger/destinations/console_destination.h"

std::string get_time_string() {
    time_t currtime;
    time(&currtime);

    struct tm *timedata = (struct tm *) malloc(sizeof(struct tm));

    LOCALTIME_SAFE(timedata, &currtime);

    char buffer[30];

    if (strftime(buffer, sizeof(buffer), "%d/%m/%Y %I:%M:%S %p", timedata) == 0) {
        free(timedata);
        return "";
    }

    free(timedata);

    return std::string(buffer);
}

std::string get_color_string(LogLevel level) {
    switch (level) {
    case LogLevel::DEBUG:
        return "\x1b[0;36m";
    case LogLevel::INFO:
        return "\x1b[0;32m";
    case LogLevel::WARN:
        return "\x1b[0;33m";
    case LogLevel::ERROR:
    case LogLevel::FATAL:
        return "\x1b[0;31m";
    }

    return "";
}

std::string get_reset_string() {
    return "\x1b[0;0m";
}

ConsoleDestination::ConsoleDestination(Logger *logger) : LogDestination(logger) {
    this->set_colored(false);
}

bool ConsoleDestination::is_colored() {
    return this->colored;
}

void ConsoleDestination::set_colored(bool colored) {
    this->colored = colored;
}

void ConsoleDestination::log(LogLevel level, std::string message) {
    std::string time_string = get_time_string();
    std::string level_string = LogLevel_name(level, true);

#ifdef _WIN32
    std::string color_string = "";
    std::string reset_string = "";
#else
    std::string color_string = this->is_colored() ? get_color_string(level) : "";
    std::string reset_string = this->is_colored() ? get_reset_string() : "";
#endif

    printf("%s - [%s%s%s] %s\n", time_string.c_str(), color_string.c_str(), level_string.c_str(), reset_string.c_str(), message.c_str());
}
