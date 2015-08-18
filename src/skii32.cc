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

#ifdef NDEBUG
    logger.set_level(LogLevel::WARN);
#else
    logger.set_level(LogLevel::DEBUG);
#endif

    return EXIT_SUCCESS;
}
