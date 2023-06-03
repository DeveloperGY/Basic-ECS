#ifndef COMPONENT_ARRAY_H
#define COMPONENT_ARRAY_H

#include "entity.h"

#include <array>
#include <unordered_map>

class _ComponentArray
{
    private:

    public:
        virtual void entity_recycled(Entity e) = 0;
};

template<class T>
class ComponentArray: public _ComponentArray
{
    private:
        std::array<T, MAX_ENTITIES> arr;
        std::unordered_map<Entity, int> eToI;
        std::unordered_map<int, Entity> iToE;
        int size;

    public:
        T &get_component(Entity e);
        void entity_recycled(Entity e) override;
};

template <class T>
T &ComponentArray<T>::get_component(Entity e)
{
    return this->arr.at(e);
}

#endif