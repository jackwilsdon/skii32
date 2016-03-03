#include <cstdlib>

#include "logger/logger.h"
#include "ecs/component_bag.h"

class NotAComponent {};
class FirstComponent : public ecs::Component {};
class SecondComponent : public ecs::Component {};

int main(int argc, char *argv[]) {
    logger::Logger log;
    ecs::ComponentBag bag;

    bag.addComponent<FirstComponent>();
    log.log("Contains FirstComponent: %s", bag.hasComponent<FirstComponent>() ? "true" : "false");

    bag.removeComponent<FirstComponent>();
    log.log("Contains FirstComponent: %s", bag.hasComponent<FirstComponent>() ? "true" : "false");

    return EXIT_SUCCESS;
}
