#include <cstdlib>
#include <ecs/type_identifier.h>

#include "logger/logger.h"

class HelloClass {};
class GoodbyeClass {};

int main(int argc, char *argv[]) {
    logger::Logger l;

    l.log(logger::Level::INFO, "Type Identifier for HelloClass: %d", ecs::TypeIdentifier::getIdentifier<HelloClass>());
    l.log(logger::Level::INFO, "Type Identifier for GoodbyeClass: %d", ecs::TypeIdentifier::getIdentifier<GoodbyeClass>());

    l.log(logger::Level::INFO, "Type Identifier for HelloClass: %d", ecs::TypeIdentifier::getIdentifier<HelloClass>());
    l.log(logger::Level::INFO, "Type Identifier for GoodbyeClass: %d", ecs::TypeIdentifier::getIdentifier<GoodbyeClass>());

    return EXIT_SUCCESS;
}
