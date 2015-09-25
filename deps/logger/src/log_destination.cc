#include "logger/log_destination.h"

LogDestination::LogDestination(Logger *logger) {
    this->logger = logger;
}

LogDestination::LogDestination(const LogDestination &destination) {
    this->logger = destination.get_logger();
}

LogDestination::~LogDestination() {}

Logger *LogDestination::get_logger() const {
    return this->logger;
}
