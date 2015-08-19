#ifndef _TYPE_IDENTIFIER_H_
#define _TYPE_IDENTIFIER_H_

#include <cstddef>

#include "platform/platform.h"

class EXPORT TypeIdentifier {
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

#endif
