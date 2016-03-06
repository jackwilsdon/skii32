#include "secsy/component_store.h"

namespace secsy {
    ComponentStore::~ComponentStore() {
        for (auto iterator = components.begin(); iterator != components.end(); /* unused */) {
            RemoveComponent(iterator++->first);
        }
    }

    bool ComponentStore::HasComponent(Identifier identifier) {
        return components.find(identifier) != components.end();
    }

    Component *ComponentStore::GetComponent(Identifier identifier) {
        if (!HasComponent(identifier)) {
            return nullptr;
        }

        return components.at(identifier);
    }

    bool ComponentStore::AddComponentInstance(Identifier identifier, Component &component) {
        if (HasComponent(identifier)) {
            return false;
        }

        components.insert(std::make_pair(identifier, &component));

        return true;
    }

    bool ComponentStore::RemoveComponent(Identifier identifier) {
        if (!HasComponent(identifier)) {
            return false;
        }

        delete GetComponent(identifier);

        return components.erase(identifier) > 0 && !HasComponent(identifier);
    }
}
