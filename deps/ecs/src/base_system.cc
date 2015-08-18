#include "ecs/base_system.h"

BaseSystem::BaseSystem() {}

void BaseSystem::setup() {
    update_filter(&type_filter);
}

bool BaseSystem::should_execute(Component *component, Identifier identifier) const {
    return type_filter.contains_identifier(identifier);
}
