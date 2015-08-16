#ifndef _TYPE_IDENTIFIER_H_
#define _TYPE_IDENTIFIER_H_

#include "platform.h"

typedef std::size_t Identifier;

template<template<class> class BaseClass>
class EXPORT TypeIdentifier {
public:
    template<typename SubType>
    static Identifier get_type_identifier() {
        static const Identifier id = next_id++;

        return id;
    }

private:
    static Identifier next_id;
};

#endif
