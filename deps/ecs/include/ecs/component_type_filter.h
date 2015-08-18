#ifndef _COMPONENT_TYPE_FILTER_H_
#define _COMPONENT_TYPE_FILTER_H_

#include <vector>

#include "ecs/type_identifier.h"

#include "platform.h"

class EXPORT ComponentTypeFilter {
public:
    ComponentTypeFilter();
    ComponentTypeFilter(const ComponentTypeFilter &filter);

    template<typename ComponentType>
    bool contains_component() const;

    bool contains_identifier(Identifier identifier) const;

    template<typename ComponentType>
    bool add_component();

    template<typename ComponentType>
    bool remove_component();

private:
    std::vector<Identifier> components;
};

#endif
