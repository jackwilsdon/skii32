#ifndef _COMPONENT_SET_EXCEPTION_H_
#define _COMPONENT_SET_EXCEPTION_H_

#include <stdexcept>
#include <string>

class ComponentSet;

class ComponentSetException : public std::runtime_error {
public:
    ComponentSetException(const ComponentSet *set, const std::string &what_arg);

    const ComponentSet *get_set() const;

private:
    const ComponentSet *set;
};

class ComponentAlreadyPresentException : public ComponentSetException {
public:
    ComponentAlreadyPresentException(const ComponentSet *set);
};

class ComponentNotFoundException : public ComponentSetException {
public:
    ComponentNotFoundException(const ComponentSet *set);
};

#endif
