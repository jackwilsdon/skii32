#ifndef TYPE_IDENTIFIER_H
#define TYPE_IDENTIFIER_H

#include <stddef.h>

#include "secsy/export.h"
#include "secsy/identifier.h"

namespace secsy {
    class SECSY_EXPORT TypeIdentifier final {
    public:
        template<typename T>
        static Identifier GetIdentifier() {
            static Identifier identifier = nextIdentifier++;

            return identifier;
        }

    private:
        static Identifier nextIdentifier;
    };
}

#endif
