#ifndef TYPE_IDENTIFIER_H
#define TYPE_IDENTIFIER_H

#include <stddef.h>

#include "ecs/export.h"

namespace ecs {
    class ECS_EXPORT TypeIdentifier final {
    public:
        typedef size_t Identifier;

        template<typename T>
        static Identifier getIdentifier() {
            static const Identifier identifier = nextIdentifier++;

            return identifier;
        }

    private:
        static Identifier nextIdentifier;
    };
}

#endif
