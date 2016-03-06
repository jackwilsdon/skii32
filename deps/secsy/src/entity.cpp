#include "secsy/entity.h"
#include "secsy/world.h"

namespace secsy {
    Entity::Entity(Identifier identifier, World &world) : identifier(identifier), world(&world) { }

    Identifier Entity::GetIdentifier() {
        return identifier;
    }

    World *Entity::GetWorld() {
        return world;
    }

    bool Entity::IsValid() {
        return world->HasEntity(identifier);
    }

    ComponentStore *Entity::GetComponentStore() {
        if (!IsValid()) {
            return nullptr;
        }

        return GetWorld()->GetComponentStore(identifier);
    }


}
