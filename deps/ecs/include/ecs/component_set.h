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
    ComponentSet();
    ~ComponentSet();

    template<class ComponentClass>
    bool add_component(ComponentClass *component, bool delete_component = false);

    template<class ComponentClass>
    ComponentClass *get_component();

    template<class ComponentClass>
    bool remove_component();

private:
    std::vector<ComponentData> *components;
};

#endif
