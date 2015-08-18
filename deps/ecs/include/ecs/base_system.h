#ifndef _BASE_SYSTEM_H_
#define _BASE_SYSTEM_H_

#include "ecs/system.h"
#include "ecs/component_type_filter.h"
#include "ecs/type_identifier.h"

#include "platform.h"

class EXPORT BaseSystem : public System {
public:
    BaseSystem();
    BaseSystem(const BaseSystem &system);

    void setup();
    virtual void update_filter(ComponentTypeFilter *filter) = 0;
    bool should_execute(Component *component, Identifier identifier) const;
    virtual void execute(Component *component, Identifier identifier) = 0;

private:
    ComponentTypeFilter type_filter;
};

#endif
