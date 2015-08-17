#ifndef _COMPONENT_SET_H_
#define _COMPONENT_SET_H_

#include <vector>

#include "ecs/type_identifier.h"

#include "platform.h"

class Component;

struct EXPORT ComponentData {
    Component *component;
    Identifier identifier;
    bool delete_component;
};

template class EXPORT std::vector<ComponentData>;

class EXPORT ComponentSet {
public:
    ComponentSet();
    ComponentSet(const ComponentSet &set);
    ~ComponentSet();

    template<typename ComponentType>
    ComponentType *get_component() const;

    template<typename ComponentType>
    bool add_component(ComponentType *component, bool delete_component = false);

    template<typename ComponentType>
    bool remove_component();

private:
    std::vector<ComponentData> components;
    bool delete_components;
};

#endif
