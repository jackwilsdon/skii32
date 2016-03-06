#ifndef ENTITY_H
#define ENTITY_H

#include <stddef.h>

#include "secsy/export.h"
#include "secsy/component_store.h"

namespace secsy {
    class World;

    class SECSY_EXPORT Entity {
    public:
        Entity(Identifier identifier, World &world);

        Identifier GetIdentifier();
        World *GetWorld();
        bool IsValid();
        ComponentStore *GetComponentStore();

        template<typename T>
        bool HasComponent() {
            if (!IsValid()) {
                return false;
            }

            return GetComponentStore()->HasComponent<T>();
        }

        template<typename T>
        T *GetComponent() {
            if (!IsValid()) {
                return nullptr;
            }

            return GetComponentStore()->GetComponent<T>();
        }

        template<typename T, typename ...A>
        T *AddComponent(A &&...args) {
            if (!IsValid()) {
                return nullptr;
            }

            return GetComponentStore()->AddComponent<T>(std::forward(args)...);
        };

        template<typename T>
        bool RemoveComponent() {
            if (!IsValid()) {
                return false;
            }

            return GetComponentStore()->RemoveComponent<T>();
        }

    private:
        Identifier identifier;
        World *world;
    };
}

#endif
