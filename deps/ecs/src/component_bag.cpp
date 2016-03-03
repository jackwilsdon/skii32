#include "ecs/component_bag.h"

namespace ecs {
    ComponentBag::ComponentBag() { }

    ComponentBag::~ComponentBag() {
        for (ComponentElement &element : elements) {
            element.destroy();
        }
    }

    bool ComponentBag::hasComponentInternal(TypeIdentifier::Identifier identifier) {
        return std::find(elements.begin(), elements.end(), ComponentElement(identifier)) != elements.end();
    }

    Component* ComponentBag::getComponentInternal(TypeIdentifier::Identifier identifier) {
        if (!hasComponentInternal(identifier)) {
            return nullptr;
        }

        ComponentElement element = *std::find(elements.begin(), elements.end(), ComponentElement(identifier));

        return element.component;
    }

    bool ComponentBag::addComponentInternal(Component &component, TypeIdentifier::Identifier identifier, bool autoDelete) {
        if (hasComponentInternal(identifier)) {
            return false;
        }

        elements.push_back(ComponentElement(&component, identifier, autoDelete));

        return true;
    }

    bool ComponentBag::removeComponentInternal(TypeIdentifier::Identifier identifier) {
        if (!hasComponentInternal(identifier)) {
            return false;
        }

        ComponentElement element = *std::find(elements.begin(), elements.end(), ComponentElement(identifier));

        element.destroy();

        elements.erase(std::remove(elements.begin(), elements.end(), element));

        return true;
    }
}
