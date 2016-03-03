#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H

#include <string>

#include "logger/level.h"

namespace logger {
    class Destination;

    class LOGGER_EXPORT Logger final {
    public:
        Logger(Level minimumLevel, Destination &destination, bool deleteDestination);
        Logger(Level minimumLevel);
        Logger(Destination &destination, bool deleteDestination);
        Logger();

        Logger(const Logger &logger);

        ~Logger();

        Level getMinimumLevel() const;
        void setMinimumLevel(Level minimumLevel);

        Destination & getDestination() const;
        bool shouldDeleteDestination() const;
        void setDestination(Destination &destination, bool deleteDestination);

        void log(Level level, std::string format, ...);
        void log(std::string format, ...);

    private:
        void vlog(Level level, std::string format, va_list args);

        void useDefaultMinimumLevel();
        void useDefaultDestination();
        void removeDestination();

        Level minimumLevel;

        Destination *destination = NULL;
        bool deleteDestination = false;
    };
}

#endif
