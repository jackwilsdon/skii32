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

        template<typename T>
        bool HasComponent() {
            return HasComponent(GetIdentifier<T>());
        }

        template<typename T>
        T *GetComponent() {
            return static_cast<T *>(GetComponent(GetIdentifier<T>()));
        }

        template<typename T, typename ...A>
        T *AddComponent(A &&...args) {
            if (HasComponent<T>()) {
                return nullptr;
            }

            T *instance = new T(std::forward<A>(args)...);

            if (!AddComponentInstance(GetIdentifier<T>(), *instance)) {
                return nullptr;
            }

            return GetComponent<T>();
        }

        template<typename T>
        bool RemoveComponent() {
            return RemoveComponent(GetIdentifier<T>());
        }

    private:
        template<typename T>
        Identifier GetIdentifier() {
            static_assert(std::is_base_of<Component, T>::value, "T must be a component");

            return TypeIdentifier::GetIdentifier<T>();
        }

        bool HasComponent(Identifier identifier);
        Component *GetComponent(Identifier identifier);
        bool AddComponentInstance(Identifier identifier, Component &component);
        bool RemoveComponent(Identifier identifier);

        std::map<Identifier, Component *> components;
    };
}

#endif
