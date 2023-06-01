#ifndef COMPONENT_H
#define COMPONENT_H

#include "entity.h"

#include <array>

template<class T>
class ComponentArray
{
    private:
        std::array<T, MAX_ENTITIES> arr;

    public:
};

#endif