#ifndef _WORLD_H_
#define _WORLD_H_

#include "ecs/entity.h"

#include <vector>

namespace ecs {
    class World {
    public:
        World();

        World(const World &world);

        bool has_entity(Entity::Identifier identifier);

        bool has_entity(Entity *entity);

        Entity *add_entity(Entity *entity);

        Entity *create_entity();

        void remove_entity(Entity::Identifier identifier);

        void remove_entity(Entity *entity);

        std::vector<Entity *> get_entities();

        Entity *get_entity(Entity::Identifier identifier);

    private:
        struct EntityData {
            Entity *entity;
            Entity::Identifier identifier;

            bool operator==(const EntityData &other) {
                return identifier == other.identifier;
            }
        };

        std::vector<EntityData> entities;
        bool delete_entities;
    };
}

#endif
