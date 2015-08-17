#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "ecs/component_set.h"

#include "platform.h"

class EXPORT Entity {
public:
    template<typename ComponentType>
    ComponentType *get_component() const;

    template<typename ComponentType>
    bool add_component(ComponentType component);

    template<typename ComponentType>
    bool add_component(ComponentType *component, bool delete_component = false);

    template<typename ComponentType, typename... Args>
    ComponentType *add_component(Args&&... args);

    template<typename ComponentType>
    bool remove_component();

private:
    ComponentSet component_set;
};

#endif
