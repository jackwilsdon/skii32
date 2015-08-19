#include "ecs/component_set_exceptions.h"

ComponentSetException::ComponentSetException(const ComponentSet *set, const std::string &what_arg) :
    runtime_error(what_arg) {

    this->set = set;
}

const ComponentSet *ComponentSetException::get_set() const {
    return set;
}

ComponentAlreadyPresentException::ComponentAlreadyPresentException(const ComponentSet *set) :
    ComponentSetException(set, "component already present in set") {}

ComponentNotFoundException::ComponentNotFoundException(const ComponentSet *set) :
    ComponentSetException(set, "component not found") {}
