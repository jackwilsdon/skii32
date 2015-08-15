#include <cstdlib>

#include "logger/logger.h"

int main(void) {
    Logger logger;

    logger.set_level(LogLevel::WARN);

    logger.log(LogLevel::DEBUG, "Hello!");
    logger.log(LogLevel::INFO, "Hello!");
    logger.log(LogLevel::WARN, "Hello!");
    logger.log(LogLevel::ERROR, "Hello!");
    logger.log(LogLevel::FATAL, "Hello!");

    return EXIT_SUCCESS;
}
