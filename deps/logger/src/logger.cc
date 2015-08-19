#include "logger/logger.h"
#include "logger/destinations/console_destination.h"
#include "logger/log_level.h"

Logger::Logger() {
    this->destination = NULL;
    this->delete_destination = false;

    this->set_destination(new ConsoleDestination(this), true);
    this->set_level(LogLevel::INFO);
}

Logger::Logger(const Logger &logger) {
    this->destination = NULL;
    this->delete_destination = false;

    this->set_destination(logger.destination, false);
    this->set_level(logger.level);
}

Logger::~Logger() {
    LogDestination *destination = this->get_destination();

    if (destination != NULL && this->delete_destination) {
        delete destination;
    }
}

LogDestination *Logger::get_destination() const {
    return this->destination;
}

void Logger::set_destination(LogDestination *destination, bool delete_destination) {
    if (this->get_destination() != NULL && this->delete_destination) {
        delete this->destination;
    }

    this->destination = destination;
    this->delete_destination = delete_destination;
}

LogLevel Logger::get_level() const {
    return this->level;
}

void Logger::set_level(LogLevel level) {
    this->level = level;
}

void Logger::vlog(LogLevel level, std::string format, va_list args) const {
    if (level < this->level) {
        return;
    }

    LogDestination *destination = this->get_destination();

    if (destination == NULL) {
        return;
    }

    const char *format_str = format.c_str();

    va_list args_copy;
    va_copy(args_copy, args);

    int formatted_length = VPRINTF_LENGTH(format_str, args_copy) + 1;

    if (formatted_length < 0) {
        return;
    }

    char *formatted_str = (char *) malloc(formatted_length);

    if (formatted_str == NULL) {
        return;
    }

    va_copy(args_copy, args);

	if (VSPRINTF_SAFE(formatted_str, formatted_length, format_str, args) < 0) {
        free(formatted_str);
        return;
    }

    std::string formatted(formatted_str);
    free(formatted_str);

    destination->log(level, formatted);
}

void Logger::log(LogLevel level, std::string format, ...) const {
    va_list args;
    va_start(args, format);

    this->vlog(level, format, args);

    va_end(args);
}

void Logger::vlog(std::string format, va_list args) const {
    this->vlog(LogLevel::INFO, format, args);
}

void Logger::log(std::string format, ...) const {
    va_list args;
    va_start(args, format);

    this->vlog(format, args);

    va_end(args);
}
