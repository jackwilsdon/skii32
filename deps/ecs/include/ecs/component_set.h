#ifndef _COMPONENT_SET_H_
#define _COMPONENT_SET_H_

#include "ecs/type_identifier.h"
#include "ecs/component.h"

#include <type_traits>
#include <vector>

#include "ecs/export.h"

class ECS_EXPORT ComponentSet {
public:
    ComponentSet();
    ComponentSet(const ComponentSet &set);
    ~ComponentSet();

    template<typename T>
    bool has_component() {
        static_assert(std::is_base_of<Component, T>::value, "T is not a Component");

        return has_component(TypeIdentifier::get_identifier<T>());
    }

    template<typename T>
    T *add_component(T* component) {
        static_assert(std::is_base_of<Component, T>::value, "T is not a Component");

        add_component(component, TypeIdentifier::get_identifier<T>());

        return component;
    }

    template<typename T, typename... Args>
    T *add_component(Args&&... args) {
        static_assert(std::is_base_of<Component, T>::value, "T is not a Component");

        T *component = new T(std::forward<Args>(args)...);

        add_component(component, TypeIdentifier::get_identifier<T>());

        return component;
    }

    template<typename T>
    void remove_component() {
        static_assert(std::is_base_of<Component, T>::value, "T is not a Component");

        remove_component(TypeIdentifier::get_identifier<T>());
    }

    template<typename T>
    T *get_component() {
        static_assert(std::is_base_of<Component, T>::value, "T is not a Component");

        return static_cast<T *>(get_component(TypeIdentifier::get_identifier<T>()));
    }

private:
    struct ComponentData {
        Component *component;
        TypeIdentifier::Identifier identifier;

        bool operator==(const ComponentData &other) {
            return identifier == other.identifier;
        }
    };

    bool has_component(TypeIdentifier::Identifier identifier);
    void add_component(Component *component, TypeIdentifier::Identifier identifier);
    void remove_component(TypeIdentifier::Identifier identifier);
    Component *get_component(TypeIdentifier::Identifier identifier);

    std::vector<ComponentData> components;
    bool delete_components;
};

#endif
