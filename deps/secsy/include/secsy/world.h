#ifndef WORLD_H
#define WORLD_H

#include <map>

#include "secsy/export.h"
#include "secsy/component_store.h"

namespace secsy {
    class Entity;

    class SECSY_EXPORT World {
    public:
        World();
        ~World();

        bool HasEntity(Identifier identifier);
        bool HasEntity(Entity &entity);
        Entity *GetEntity(Identifier identifier);
        ComponentStore *GetComponentStore(Identifier identifier);
        ComponentStore *GetComponentStore(Entity &entity);
        Entity *CreateEntity();
        bool RemoveEntity(Identifier identifier);
        bool RemoveEntity(Entity &entity);

    private:
        Identifier nextIdentifier;

        std::map<Identifier, Entity *> entities;
        std::map<Identifier, ComponentStore *> components;
    };
}

#endif
