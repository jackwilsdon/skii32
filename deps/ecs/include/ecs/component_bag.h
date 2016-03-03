#ifndef COMPONENT_BAG_H
#define COMPONENT_BAG_H

#include <type_traits>
#include <vector>

#include "ecs/export.h"

#include "ecs/component.h"
#include "ecs/type_identifier.h"

namespace ecs {
    class ECS_EXPORT ComponentBag final {
    public:
        ComponentBag();
        ComponentBag(const ComponentBag &componentBag) = delete;

        ~ComponentBag();

        template<typename T>
        bool hasComponent() {
            ensureComponentType<T>();

            return hasComponentInternal(getComponentIdentifier<T>());
        }

        template<typename T>
        T *getComponent() {
            ensureComponentType<T>();

            return getComponentInternal(getComponentIdentifier<T>());
        }

        template<typename T, typename... A>
        T *addComponent(A &&...constructorArguments) {
            ensureComponentType<T>();

            T *component = new T(std::forward(constructorArguments)...);

            if (!addComponentInternal(*component, getComponentIdentifier<T>(), true)) {
                delete component;

                return nullptr;
            }

            return component;
        }

        template<typename T>
        bool removeComponent() {
            ensureComponentType<T>();

            return removeComponentInternal(getComponentIdentifier<T>());
        }

    private:
        struct ComponentElement {
            Component *component;
            TypeIdentifier::Identifier identifier;
            bool autoDelete;

            ComponentElement(Component *component, TypeIdentifier::Identifier identifier, bool autoDelete) {
                this->component = component;
                this->identifier = identifier;
                this->autoDelete = autoDelete;
            }

            ComponentElement(TypeIdentifier::Identifier identifier) : ComponentElement(nullptr, identifier, false) { }

            void destroy() {
                if (autoDelete) {
                    delete component;
                }
            }

            bool operator==(const ComponentElement &element) {
                return identifier == element.identifier;
            }
        };

        template<typename T>
        void ensureComponentType() {
            static_assert(std::is_base_of<Component, T>::value, "passed type must be a component");
        }

        template<typename T>
        TypeIdentifier::Identifier getComponentIdentifier() {
            ensureComponentType<T>();

            return TypeIdentifier::getIdentifier<T>();
        }

        bool hasComponentInternal(TypeIdentifier::Identifier identifier);
        Component *getComponentInternal(TypeIdentifier::Identifier identifier);
        bool addComponentInternal(Component &component, TypeIdentifier::Identifier identifier, bool autoDelete);
        bool removeComponentInternal(TypeIdentifier::Identifier identifier);

        std::vector<ComponentElement> elements;
    };
}

#endif
