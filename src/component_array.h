#ifndef COMPONENT_ARRAY_H
#define COMPONENT_ARRAY_H

#include "entity.h"

#include <array>

class _ComponentArray
{
    private:

    public:
};

template<class T>
class ComponentArray: public _ComponentArray
{
    private:
        std::array<T, MAX_ENTITIES> arr;

    public:
        T &get_component(Entity e);
};

template <class T>
T &ComponentArray<T>::get_component(Entity e)
{
    return this->arr.at(e);
}

#endif