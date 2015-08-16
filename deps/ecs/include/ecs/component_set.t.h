#ifndef _COMPONENT_SET_T_H_
#define _COMPONENT_SET_T_H_

#include "ecs/component_set.h"

#include <vector>

#include "ecs/component.h"

#include "platform.h"

ComponentSet::ComponentSet() {
    delete_components = true;
}

ComponentSet::ComponentSet(const ComponentSet &set) {
    components = set.components;
    delete_components = false;
}

ComponentSet::~ComponentSet() {
    if (delete_components) {
        std::vector<ComponentData> components = this->components;
        std::vector<ComponentData>::iterator iterator;

        for (iterator = components.begin(); iterator < components.end(); iterator++) {
            ComponentData component_data = *iterator;

            if (component_data.delete_component) {
                delete component_data.component;
            }
        }
    }
}

template<typename ComponentType>
bool ComponentSet::add_component(ComponentType *component, bool delete_component) {
    if (!std::is_base_of<Component, ComponentType>()) {
        return false;
    }

    if (component->IDENTIFIER == Component::INVALID_IDENTIFIER) {
        return false;
    }

    if (get_component<ComponentType>() != nullptr) {
        return false;
    }

    struct ComponentData component_data;

    component_data.component = component;
    component_data.delete_component = delete_component;

    components.push_back(component_data);

    return true;
}

template<typename ComponentType>
ComponentType *ComponentSet::get_component() const {
    if (!std::is_base_of<Component, ComponentType>()) {
        return nullptr;
    }

    std::vector<ComponentData> components = this->components;
    std::vector<ComponentData>::iterator iterator;

    for (iterator = components.begin(); iterator < components.end(); iterator++) {
        ComponentData component_data = *iterator;
        ComponentType *component = static_cast<ComponentType *>(component_data.component);

        if (component->IDENTIFIER == ComponentType::IDENTIFIER) {
            return component;
        }
    }

    return nullptr;
}

template<typename ComponentType>
bool ComponentSet::remove_component() {
    if (!std::is_base_of<Component, ComponentType>()) {
        return false;
    }

    std::vector<ComponentData> components = this->components;
    std::vector<ComponentData>::iterator iterator = components.begin();

    for (iterator = components.begin(); iterator < components.end(); iterator++) {
        ComponentData component_data = *iterator;
        ComponentType *component = static_cast<ComponentType *>(component_data.component);

        if (component->IDENTIFIER == ComponentType::IDENTIFIER) {
            components.erase(iterator);
            return true;
        }
    }

    return false;
}

#endif
