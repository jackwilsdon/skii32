#ifndef _ENTITY_T_H_
#define _ENTITY_T_H_

#include "ecs/entity.h"

#include "ecs/component_set.t.h"

template<typename ComponentType>
bool Entity::add_component(ComponentType component) {
    return add_component(&component, false);
}

template<typename ComponentType>
bool Entity::add_component(ComponentType *component, bool delete_component) {
    return component_set.add_component(component, delete_component);
}

template<typename ComponentType, typename... Args>
ComponentType *Entity::add_component(Args&&... args) {
    ComponentType *component = new ComponentType(std::forward<Args>(args)...);

    if (!add_component(component, true)) {
        delete component;
        return nullptr;
    }

    return component;
}

template<typename ComponentType>
ComponentType *Entity::get_component() const {
    return component_set.get_component<ComponentType>();
}

template<typename ComponentType>
bool Entity::remove_component() {
    return component_set.remove_component<ComponentType>();
}

#endif
