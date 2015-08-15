#ifndef _ENTITY_T_H_
#define _ENTITY_T_H_

#include "ecs/entity.h"

template<class ComponentClass>
bool Entity::add_component(ComponentClass component) {
    return this->add_component(&component, false);
}

template<class ComponentClass>
bool Entity::add_component(ComponentClass *component, bool delete_component) {
    return this->component_set.add_component(component, delete_component);
}

template<class ComponentClass>
ComponentClass *Entity::get_component() {
    return this->component_set.get_component<ComponentClass>();
}

template<class ComponentClass>
bool Entity::remove_component() {
    return this->component_set.remove_component<ComponentClass>();
}

#endif