#ifndef _COMPONENT_SET_T_H_
#define _COMPONENT_SET_T_H_

#include "ecs/component_set.h"

#include <vector>

#include "ecs/component.h"

#include "platform.h"

ComponentSet::ComponentSet() {
    components = new std::vector<ComponentData>();
}

ComponentSet::~ComponentSet() {
    std::vector<ComponentData> components = *this->components;
    std::vector<ComponentData>::iterator iterator;

    for (iterator = components.begin(); iterator < components.end(); iterator++) {
        ComponentData component_data = *iterator;

        if (component_data.delete_component) {
            delete component_data.component;
        }
    }

    delete this->components;
}

template<class ComponentClass>
bool ComponentSet::add_component(ComponentClass *component, bool delete_component) {
    if (!std::is_base_of<Component, ComponentClass>()) {
        return false;
    }

    if (component->IDENTIFIER == Component::INVALID_IDENTIFIER) {
        return false;
    }

    if (get_component<ComponentClass>() != nullptr) {
        return false;
    }

    struct ComponentData component_data;

    component_data.component = component;
    component_data.delete_component = delete_component;

    components->push_back(component_data);

    return true;
}

template<class ComponentClass>
ComponentClass *ComponentSet::get_component() const {
    if (!std::is_base_of<Component, ComponentClass>()) {
        return nullptr;
    }

    std::vector<ComponentData> components = *this->components;
    std::vector<ComponentData>::iterator iterator;

    for (iterator = components.begin(); iterator < components.end(); iterator++) {
        ComponentData component_data = *iterator;
        ComponentClass *component = static_cast<ComponentClass *>(component_data.component);

        if (component->IDENTIFIER == ComponentClass::IDENTIFIER) {
            return component;
        }
    }

    return nullptr;
}

template<class ComponentClass>
bool ComponentSet::remove_component() {
    if (!std::is_base_of<Component, ComponentClass>()) {
        return false;
    }

    std::vector<ComponentData> components = *this->components;
    std::vector<ComponentData>::iterator iterator = components.begin();

    for (iterator = components.begin(); iterator < components.end(); iterator++) {
        ComponentData component_data = *iterator;
        ComponentClass *component = static_cast<ComponentClass *>(component_data.component);

        if (component->IDENTIFIER == ComponentClass::IDENTIFIER) {
            components.erase(iterator);
            return true;
        }
    }

    return false;
}

#endif
