#include "logger/destination.h"

namespace logger {
    Destination::Destination(Logger &logger) {
        this->logger = &logger;
    }

    Destination::~Destination() {

    }

    Logger& Destination::getLogger() const {
        return *this->logger;
    }
}
