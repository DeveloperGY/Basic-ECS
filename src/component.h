#ifndef COMPONENT_H
#define COMPONENT_H

#include "component_array.h"

#include <memory>
#include <unordered_map>
#include <string>
#include <typeinfo>

typedef int Component;

class Components
{
    private:
        static std::unordered_map<std::string, std::shared_ptr<_ComponentArray>> component_arrays;

    public:
        template <class T>
        static void register_component();
};

template <class T>
void Components::register_component()
{
    std::string name = typeid(T).name();

    if (Components::component_arrays.find(name) == Components::component_arrays.end())
    {
        std::shared_ptr<_ComponentArray> ptr = std::static_pointer_cast<_ComponentArray>(std::make_shared<ComponentArray<T>>());
        Components::component_arrays.insert({name, ptr});
    }

    return;
}




#endif