#ifndef COMPONENT_H
#define COMPONENT_H

#include <type_traits>

#include "secsy/export.h"
#include "secsy/identifier.h"
#include "secsy/type_identifier.h"

namespace secsy {
    class SECSY_EXPORT Component {
    public:
        virtual ~Component() = 0;

        template<typename T>
        static Identifier GetIdentifier() {
            static_assert(std::is_base_of<Component, T>::value, "T must be a component");

            return TypeIdentifier::GetIdentifier<T>();
        }
    };
}

#endif
