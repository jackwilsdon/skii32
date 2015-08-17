#ifndef _COMPONENT_FILTER_H_
#define _COMPONENT_FILTER_H_

#include "ecs/type_identifier.h"

class ComponentFilter {
public:
    ComponentFilter();
    ComponentFilter(const ComponentFilter &filter);

    template<typename ComponentType>
    bool contains_component() const;

    template<typename ComponentType>
    bool add_component();

    template<typename ComponentType>
    bool remove_component();

private:
    std::vector<Identifier> components;
};

#endif
