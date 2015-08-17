#ifndef _COMPONENT_TYPE_FILTER_T_H_
#define _COMPONENT_TYPE_FILTER_T_H_

#include "ecs/component_type_filter.h"

#include <algorithm>

ComponentTypeFilter::ComponentFilter() {}

ComponentTypeFilter::ComponentFilter(const ComponentFilter &filter) {
    components = filter.components;
}

template<typename ComponentType>
bool ComponentTypeFilter::contains_component() const {
    if (!std::is_base_of<Component, ComponentType>()) {
        return false;
    }

    Identifier component_identifier = TypeIdentifier::get_identifier<ComponentType>();

    std::vector<Identifier>::const_iterator iterator = std::find(components.begin(), components.end(), component_identifier);

    return iterator != components.end();
}

template<typename ComponentType>
bool ComponentTypeFilter::add_component() {
    if (!std::is_base_of<Component, ComponentType>()) {
        return false;
    }

    if (contains_component<ComponentType>()) {
        return false;
    }

    components.push_back(TypeIdentifier::get_identifier<ComponentType>());

    return true;
}

template<typename ComponentType>
bool ComponentTypeFilter::remove_component() {
    if (!std::is_base_of<Component, ComponentType>()) {
        return false;
    }

    if (!contains_component<ComponentType>()) {
        return false;
    }

    Identifier component_identifier = TypeIdentifier::get_identifier<ComponentType>();

    std::vector<Identifier>::iterator iterator = std::remove(components.begin(), components.end(), component_identifier);

    if (iterator == components.end()) {
        return false;
    }

    components.erase(iterator);

    return true;
}

#endif
