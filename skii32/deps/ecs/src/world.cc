#include "ecs/world.h"

#include "massert/massert.h"

#include <algorithm>

namespace ecs {
    World::World() {
        delete_entities = true;
    }

    World::World(const World &world) {
        entities = world.entities;
        delete_entities = false;
    }

    bool World::has_entity(Entity::Identifier identifier) {
        struct EntityData entity_data;

        entity_data.entity = NULL;
        entity_data.identifier = identifier;

        return std::find(entities.begin(), entities.end(), entity_data) != entities.end();
    }

    bool World::has_entity(Entity *entity) {
        return has_entity(entity->get_identifier());
    }

    void World::remove_entity(Entity::Identifier identifier) {
        massert(has_entity(identifier), "entity not present in world");

        struct EntityData entity_data;

        entity_data.entity = NULL;
        entity_data.identifier = identifier;

        entities.erase(std::remove(entities.begin(), entities.end(), entity_data));
    }

    void World::remove_entity(Entity *entity) {
        return remove_entity(entity->get_identifier());
    }

    std::vector<Entity *> World::get_entities() {
        std::vector<Entity *> all_entities;

        std::vector<EntityData>::iterator iterator;

        for (iterator = entities.begin(); iterator < entities.end(); iterator++) {
            all_entities.push_back(iterator->entity);
        }

        return all_entities;
    }

    Entity *World::get_entity(Entity::Identifier identifier) {
        massert(has_entity(identifier), "entity not present in world");

        struct EntityData entity_data;

        entity_data.entity = NULL;
        entity_data.identifier = identifier;

        std::vector<EntityData>::iterator found_entity_data = std::find(entities.begin(), entities.end(), entity_data);

        if (found_entity_data == entities.end()) {
            return nullptr;
        }

        return found_entity_data->entity;
    }
}