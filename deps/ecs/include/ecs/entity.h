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

    template<typename T>
    bool has_component() {
        return components.has_component<T>();
    }

    template<typename T>
    T *add_component(T* component) {
        return components.add_component(component);
    }

    template<typename T, typename... Args>
    T *add_component(Args&&... args) {
        return components.add_component<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    void remove_component() {
        return components.remove_component<T>();
    }

    template<typename T>
    T *get_component() {
        return components.get_component<T>();
    }

    bool operator==(const Entity &other);

private:
    Identifier identifier;

    ComponentSet components;

    static Identifier next_identifier;
};

#endif
