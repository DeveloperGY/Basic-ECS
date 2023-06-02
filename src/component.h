#ifndef COMPONENT_H
#define COMPONENT_H

#include "component_array.h"

#include <vector>
#include <memory>

typedef int Component;

class Components
{
    private:
        static std::vector<std::unique_ptr<_ComponentArray>> component_arrays;
        static int next_id;

    public:
        template <class T>
        static Component register_component();
};

template <class T>
Component Components::register_component()
{
    return this->next_id++;
}

#endif