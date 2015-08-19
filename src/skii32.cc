#include <cstdlib>

#ifdef __unix
    #include <unistd.h>
#endif

#include "logger/logger.h"
#include "logger/destinations/console_destination.h"

#include "ecs/entity.h"

class MyComponent : public Component {
public:
    MyComponent(const char *message) {
        this->message = message;
    }

    const char *message;
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

    Entity e;

    e.add_component<MyComponent>("Hello!");
    logger.log("MyComponent says \"%s\"", e.get_component<MyComponent>()->message);

    return EXIT_SUCCESS;
}
