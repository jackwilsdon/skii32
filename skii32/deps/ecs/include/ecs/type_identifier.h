#ifndef _TYPE_IDENTIFIER_H_
#define _TYPE_IDENTIFIER_H_

#include <cstddef>

#include "ecs/export.h"

namespace ecs {
    class ECS_EXPORT TypeIdentifier {
    public:
        typedef std::size_t Identifier;

        template<typename T>
        static Identifier get_identifier() {
            static const Identifier current_identifier = next_identifier++;

            return current_identifier;
        }

    private:
        static Identifier next_identifier;
    };
}

#endif
