#include <stdlib.h>

#include "logger/logger.h"
#include "logger/platform.h"
#include "logger/destinations/console_destination.h"

namespace logger {
    Logger::Logger(Level minimumLevel, Destination &destination, bool deleteDestination) {
        setMinimumLevel(minimumLevel);
        setDestination(destination, deleteDestination);
    }

    Logger::Logger(Level minimumLevel) {
        setMinimumLevel(minimumLevel);
        useDefaultDestination();
    }

    Logger::Logger(Destination &destination, bool deleteDestination) {
        useDefaultMinimumLevel();
        setDestination(destination, deleteDestination);
    }

    Logger::Logger() {
        useDefaultMinimumLevel();
        useDefaultDestination();
    }

    Logger::Logger(const Logger &logger) {
        setMinimumLevel(logger.getMinimumLevel());
        setDestination(*logger.getDestination().clone(), true);
    }

    Logger::~Logger() {
        removeDestination();
    }

    Level Logger::getMinimumLevel() const {
        return minimumLevel;
    }

    void Logger::setMinimumLevel(Level minimumLevel) {
        this->minimumLevel = minimumLevel;
    }

    Destination& Logger::getDestination() const {
        return *destination;
    }

    bool Logger::shouldDeleteDestination() const {
        return deleteDestination;
    }

    void Logger::setDestination(Destination &destination, bool deleteDestination) {
        removeDestination();

        this->destination = &destination;
        this->deleteDestination = deleteDestination;
    }

    void Logger::log(Level level, std::string format, ...) {
        va_list args;

        va_start(args, format);

        vlog(level, format, args);

        va_end(args);
    }

    void Logger::log(std::string format, ...) {
        va_list args;

        va_start(args, format);

        vlog(Level::INFO, format, args);

        va_end(args);
    }

    void Logger::vlog(Level level, std::string format, va_list args){
        if (level < getMinimumLevel()) {
            return;
        }

        const char *formatString = format.c_str();

        va_list argCopy;

        va_copy(argCopy, args);

        int formattedLength = VPRINTF_LENGTH(formatString, argCopy);

        if (formattedLength < 0) {
            return;
        }

        char *formattedCharArray = (char *) malloc((formattedLength + 1) * sizeof(char));

        if (formattedCharArray == NULL) {
            return;
        }

        va_copy(argCopy, args);

        if (VSPRINTF_SAFE(formattedCharArray, formattedLength, formatString, argCopy) < 0) {
            free(formattedCharArray);
            return;
        }

        std::string formattedString(formattedCharArray);

        free(formattedCharArray);

        getDestination().log(level, formattedString);
    }

    void Logger::useDefaultMinimumLevel() {
        setMinimumLevel(Level::INFO);
    }

    void Logger::useDefaultDestination() {
        setDestination(*new ConsoleDestination(*this), true);
    }

    void Logger::removeDestination() {
        if (shouldDeleteDestination()) {
            delete &getDestination();
        }
    }
}
