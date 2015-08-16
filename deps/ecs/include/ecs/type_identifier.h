#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "component_set.t.h"

#include "platform.h"

class EXPORT Entity {
    typedef std::size_t TypeIdentifier;

public:
    template<class ComponentClass>

private:
    static TypeIdentifier next_id;
};

#endif
