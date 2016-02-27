#include <cstdlib>

#include "massert/massert.h"

#include "logger/logger.h"
#include "logger/destinations/console_destination.h"

#include "ecs/entity.h"

class MyComponent : public ecs::Component {
public:
    MyComponent(const char *message) {
        this->message = message;
    }

    const char *message;
};

int main(int argc, char *argv[]) {
    Logger logger;

    ((ConsoleDestination *) logger.get_destination())->set_colored(false);

    ecs::Entity e;

    e.add_component<MyComponent>("Hello!");
    logger.log("MyComponent says \"%s\"", e.get_component<MyComponent>()->message);

    return EXIT_SUCCESS;
}
