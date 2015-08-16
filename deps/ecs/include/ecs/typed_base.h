#ifndef _TYPED_BASE_H_
#define _TYPED_BASE_H_

#include "type_identifier.h"

#include "platform.h"

template<typename BaseType>
class EXPORT TypedBase {
public:
    static Identifier GetTypeIdentifier();
}

#endif
