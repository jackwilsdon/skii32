#include <cstdlib>

#ifdef __unix
    #include <unistd.h>
#endif

#include "logger/logger.h"
#include "logger/destinations/console_destination.h"

#include "ecs/entity.t.h"
#include "ecs/component.h"

class SimpleComponent: public Component {
public:
    static const unsigned int IDENTIFIER = 1;

    void log(Logger logger) {
        logger.log(LogLevel::DEBUG, "Hello from SimpleComponent!");
    }
};

int main(void) {
    Logger logger;

    Entity entity;

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

    entity.add_component<SimpleComponent>();

    entity.get_component<SimpleComponent>()->log(logger);

    return EXIT_SUCCESS;
}
