#ifndef _COMPONENT_SET_H_
#define _COMPONENT_SET_H_

#include <vector>

#include "platform.h"

class Component;

struct EXPORT ComponentData {
    Component *component;
    bool delete_component;
};

template class EXPORT std::vector<ComponentData>;

class EXPORT ComponentSet {
public:
    ComponentSet();
    ComponentSet(const ComponentSet &set);
    ~ComponentSet();

    template<class ComponentClass>
    bool add_component(ComponentClass *component, bool delete_component = false);

    template<class ComponentClass>
    ComponentClass *get_component() const;

    template<class ComponentClass>
    bool remove_component();

private:
    std::vector<ComponentData> components;
    bool delete_components;
};

#endif
