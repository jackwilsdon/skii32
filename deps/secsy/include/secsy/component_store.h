#ifndef COMPONENT_STORE_H
#define COMPONENT_STORE_H

#include <assert.h>

#include <type_traits>
#include <map>

#include "secsy/export.h"
#include "secsy/component.h"
#include "secsy/type_identifier.h"

namespace secsy {
    class SECSY_EXPORT ComponentStore {
    public:
        ~ComponentStore();

        bool HasComponent(Identifier identifier);

        template<typename T>
        bool HasComponent() {
            return HasComponent(Component::GetIdentifier<T>());
        }

        Component *GetComponent(Identifier identifier);

        template<typename T>
        T *GetComponent() {
            return static_cast<T *>(GetComponent(Component::GetIdentifier<T>()));
        }

        template<typename T, typename ...A>
        T *AddComponent(A &&...args) {
            if (HasComponent<T>()) {
                return nullptr;
            }

            T *instance = new T(std::forward<A>(args)...);

            if (!AddComponentInstance(Component::GetIdentifier<T>(), *instance)) {
                return nullptr;
            }

            return GetComponent<T>();
        }

        bool RemoveComponent(Identifier identifier);

        template<typename T>
        bool RemoveComponent() {
            return RemoveComponent(Component::GetIdentifier<T>());
        }

    private:
        bool AddComponentInstance(Identifier identifier, Component &component);

        std::map<Identifier, Component *> components;
    };
}

#endif
