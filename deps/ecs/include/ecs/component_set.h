#ifndef _COMPONENT_SET_H_
#define _COMPONENT_SET_H_

#include <vector>

#include "platform.h"

class Component;

struct EXPORT ComponentData {
    Component *component;
    bool delete_component;
};

class EXPORT ComponentSet {
public:
    ComponentSet() {
        this->components = new std::vector<ComponentData>();
    }

    ~ComponentSet() {
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
    bool add_component(ComponentClass *component, bool delete_component = false) {
        if (!std::is_base_of<Component, ComponentClass>()) {
            return false;
        }

        if (component->IDENTIFIER == Component::INVALID_IDENTIFIER) {
            return false;
        }

        if (this->get_component<ComponentClass>() != nullptr) {
            return false;
        }

        struct ComponentData component_data = {
            .component = component,
            .delete_component = delete_component
        };

        this->components->push_back(component_data);

        return true;
    }

    template<class ComponentClass>
    ComponentClass *get_component() {
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
    bool remove_component() {
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

private:
    std::vector<ComponentData> *components;
};

#endif
