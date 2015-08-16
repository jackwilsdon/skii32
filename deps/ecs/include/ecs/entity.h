#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "component_set.t.h"

#include "platform.h"

class EXPORT Entity {
public:
    template<class ComponentClass>
    bool add_component(ComponentClass component);

    template<class ComponentClass>
    bool add_component(ComponentClass *component, bool delete_component = false);

    template<class ComponentClass, typename... Args>
    ComponentClass *add_component(Args&&... args);

    template<class ComponentClass>
    ComponentClass *get_component();

    template<class ComponentClass>
    bool remove_component();

private:
    ComponentSet component_set;
};

#endif
