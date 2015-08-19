#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "ecs/type_identifier.h"
#include "ecs/component_set.h"

#include "platform/platform.h"

class EXPORT Entity {
public:
    typedef TypeIdentifier::Identifier Identifier;

    Entity();
    Entity(const Entity &entity);

    Identifier get_identifier() const;



private:
    Identifier identifier;

    ComponentSet components;

    static Identifier next_identifier;
};

#endif
