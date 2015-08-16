#ifndef _TYPED_BASE_H_
#define _TYPED_BASE_H_

#include "ecs/type_identifier.h"

#include "platform.h"

template<template<class> class BaseClass, typename SubType>
class EXPORT Typed {
public:
    static Identifier get_type_identifier();
};

#endif
