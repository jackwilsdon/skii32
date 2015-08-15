#include "logger/log_destination.h"

LogDestination::LogDestination(Logger *logger) {
    this->logger = logger;
}

Logger *LogDestination::get_logger() {
    return this->logger;
}
