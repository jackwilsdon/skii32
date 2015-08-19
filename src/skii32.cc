#include <cstdlib>

#ifdef __unix
    #include <unistd.h>
#endif

#include "logger/logger.h"
#include "logger/destinations/console_destination.h"

#include "ecs/component_set.h"

class MyComponent : public Component {
public:
    void log(Logger logger) {
        logger.log(LogLevel::WARN, "Hello from MyComponent at %p!", this);
    }
};

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

    ComponentSet set;

    set.add_component(new MyComponent());
    set.get_component<MyComponent>()->log(logger);
    set.get_component<MyComponent>()->log(logger);

    return EXIT_SUCCESS;
}
