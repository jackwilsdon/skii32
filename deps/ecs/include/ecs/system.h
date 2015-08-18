#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "ecs/type_identifier.h"

#include "platform.h"

class Component;

class EXPORT System {
public:
    virtual void setup() = 0;
    virtual bool should_execute(Component *component, Identifier identifier) const = 0;
    virtual void execute(Component *component, Identifier identifier) = 0;
};

#endif
