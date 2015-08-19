#include "ecs/entity.h"

Entity::Entity() {
    identifier = next_identifier++;
}

Entity::Entity(const Entity &entity) {
    identifier = entity.identifier;
    components = entity.components;
}

Entity::Identifier Entity::get_identifier() const {
    return identifier;
}

Entity::Identifier Entity::next_identifier = 0;
