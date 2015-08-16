#ifndef _TYPE_IDENTIFIER_T_H_
#define _TYPE_IDENTIFIER_T_H_

#include "ecs/type_identifier.h"

template <typename BaseType>
Identifier TypeIdentifier<BaseType>::next_id = 0;

#endif
