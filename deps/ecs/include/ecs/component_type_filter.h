#ifndef _COMPONENT_TYPE_FILTER_H_
#define _COMPONENT_TYPE_FILTER_H_

#include "ecs/component_filter.h"
#include "ecs/type_identifier.h"

class ComponentTypeFilter : ComponentFilter {
public:
    ComponentTypeFilter();
    ComponentTypeFilter(const ComponentTypeFilter &filter);

    template<typename ComponentType>
    bool contains_component() const;

    template<typename ComponentType>
    bool add_component();

    template<typename ComponentType>
    bool remove_component();;

private:
    std::vector<Identifier> components;
};

#endif
