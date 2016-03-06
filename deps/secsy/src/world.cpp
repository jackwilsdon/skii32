#include "secsy/world.h"
#include "secsy/entity.h"

namespace secsy {
    World::World() : nextIdentifier(0) { }

    World::~World() {
        for (auto iterator = entities.begin(); iterator != entities.end(); /* unused */) {
            RemoveEntity(iterator++->first);
        }
    }

    bool World::HasEntity(Identifier identifier) {
        return entities.find(identifier) != entities.end();
    }

    bool World::HasEntity(Entity &entity) {
        return HasEntity(entity.GetIdentifier());
    }

    Entity *World::GetEntity(Identifier identifier) {
        if (!HasEntity(identifier)) {
            return nullptr;
        }

        return entities.at(identifier);
    }

    ComponentStore *World::GetComponentStore(Identifier identifier) {
        if (!HasEntity(identifier)) {
            return nullptr;
        }

        return components.at(identifier);
    }

    ComponentStore *World::GetComponentStore(Entity &entity) {
        return GetComponentStore(entity.GetIdentifier());
    }

    Entity *World::CreateEntity() {
        Entity *entity = new Entity(nextIdentifier++, *this);
        ComponentStore *store = new ComponentStore();

        entities.insert(std::make_pair(entity->GetIdentifier(), entity));
        components.insert(std::make_pair(entity->GetIdentifier(), store));

        return entity;
    }

    bool World::RemoveEntity(Identifier identifier) {
        if (!HasEntity(identifier)) {
            return false;
        }

        delete GetEntity(identifier);
        delete GetComponentStore(identifier);

        // we use a bitwise and instead of a conditional and to ensure both erase methods are
        // called but the result is the same as if we used a conditional
        return (entities.erase(identifier) & components.erase(identifier)) == 1;
    }

    bool World::RemoveEntity(Entity &entity) {
        return RemoveEntity(entity.GetIdentifier());
    }
}
