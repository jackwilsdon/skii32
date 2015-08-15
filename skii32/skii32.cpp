#include <cstdlib>

#ifdef __unix
    #include <unistd.h>
#endif

#include "logger/logger.h"
#include "logger/destinations/console_destination.h"

int main(void) {
    Logger logger;

#ifdef __unix
    if(isatty(STDOUT_FILENO)) {
        ((ConsoleDestination *) logger.get_destination())->set_colored(true);
    }
#endif

    logger.set_level(LogLevel::WARN);

    logger.log(LogLevel::DEBUG, "Hello!");
    logger.log(LogLevel::INFO, "Hello!");
    logger.log(LogLevel::WARN, "Hello!");
    logger.log(LogLevel::ERROR, "Hello!");
    logger.log(LogLevel::FATAL, "Hello!");

    return EXIT_SUCCESS;
}
