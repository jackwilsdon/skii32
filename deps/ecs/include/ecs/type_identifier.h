#ifndef _TYPE_IDENTIFIER_H_
#define _TYPE_IDENTIFIER_H_

#include "platform.h"

typedef std::size_t Identifier;

class TypeIdentifier {
public:
    template<typename Type>
    static Identifier get_identifier() {
        static const Identifier current_identifier = ++next_identifier;

        return current_identifier;
    }

private:
    static Identifier next_identifier;
};

#endif
