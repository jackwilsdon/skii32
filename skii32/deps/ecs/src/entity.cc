#include "ecs/entity.h"

namespace ecs {
    Entity::Entity() {
        identifier = next_identifier++;
    }

    Entity::Entity(const Entity &entity) {
        identifier = entity.identifier;
        components = ComponentSet(entity.components);
    }

    Entity::Identifier Entity::get_identifier() const {
        return identifier;
    }

    bool Entity::operator==(const Entity &other) {
        return identifier == other.identifier;
    }

    Entity::Identifier Entity::next_identifier = 0;
}