#ifndef _TYPE_IDENTIFIER_H_
#define _TYPE_IDENTIFIER_H_

#include "platform.h"

typedef std::size_t Identifier;

template<typename BaseType>
class EXPORT TypeIdentifier {
public:
    template<typename SubType>
    static Identifier GetIdentifier() {
        static const Identifier id = next_id++;

        return id;
    }

private:
    static Identifier next_id;
};

#endif
