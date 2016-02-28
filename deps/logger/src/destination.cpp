#include <logger/destination.h>
#include <logger/level.h>

namespace logger {
    Destination::Destination(Logger &logger) {
        this->logger = &logger;
    }

    Destination::Destination(const Destination &destination) {
        this->logger = &destination.getLogger();
    }

    Destination::~Destination() {

    }

    Logger& Destination::getLogger() const {
        return *this->logger;
    }
}
