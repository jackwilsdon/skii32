#include "ecs/component_set.h"

#include "ecs/type_identifier.h"

#include "massert/massert.h"

#include <algorithm>

ComponentSet::ComponentSet() {
    delete_components = true;
}

ComponentSet::ComponentSet(const ComponentSet &set) {
    components = set.components;
    delete_components = false;
}

ComponentSet::~ComponentSet() {
    if (delete_components) {
        std::vector<ComponentData>::iterator iterator;

        for (iterator = components.begin(); iterator < components.end(); iterator++) {
            delete iterator->component;
        }
    }
}

bool ComponentSet::has_component(TypeIdentifier::Identifier identifier) {
    struct ComponentData component_data;

    component_data.component = NULL;
    component_data.identifier = identifier;

    return std::find(components.begin(), components.end(), component_data) != components.end();
}

void ComponentSet::add_component(Component *component, TypeIdentifier::Identifier identifier) {
    massert(!has_component(identifier), "component already present in set");

    struct ComponentData component_data;

    component_data.component = component;
    component_data.identifier = identifier;

    components.push_back(component_data);
}

void ComponentSet::remove_component(TypeIdentifier::Identifier identifier) {
    massert(has_component(identifier), "component not present in set");

    struct ComponentData component_data;

    component_data.component = NULL;
    component_data.identifier = identifier;

    components.erase(std::remove(components.begin(), components.end(), component_data));
}

Component *ComponentSet::get_component(TypeIdentifier::Identifier identifier) {
    massert(has_component(identifier), "component not present in set");

    struct ComponentData component_data;

    component_data.component = NULL;
    component_data.identifier = identifier;

    ComponentData data = *std::find(components.begin(), components.end(), component_data);

    return data.component;
}
