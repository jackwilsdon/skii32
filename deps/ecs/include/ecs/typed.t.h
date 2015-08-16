#ifndef _TYPED_BASE_T_H_
#define _TYPED_BASE_T_H_

#include "ecs/typed.h"

#include "ecs/type_identifier.t.h"

#include "platform.h"

template<template<typename> class BaseClass, typename SubType>
Identifier Typed<BaseClass, SubType>::get_type_identifier() {
    return TypeIdentifier<BaseClass>::template get_type_identifier<SubType>();
}

#endif
