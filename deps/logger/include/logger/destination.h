#ifndef DESTINATION_H
#define DESTINATION_H

#include "logger/level.h"

namespace logger {
    class Logger;

    class LOGGER_EXPORT Destination {
    public:
        Destination(Logger &logger);
        Destination(const Destination &destination) = delete;

        virtual ~Destination();

        Logger& getLogger() const;
        virtual void log(Level level, std::string message) = 0;

        virtual Destination* clone() const = 0;

    private:
        Logger *logger;
    };
}

#endif
