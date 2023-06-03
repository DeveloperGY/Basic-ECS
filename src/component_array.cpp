#include "component_array.h"

template <class T>
void ComponentArray<T>::entity_recycled(Entity old_entity)
{
    if (this->eToI.find(e) == this->eToI.end())
    {
        return;
    }

    int old_index = this->eToI.at(e);
    

    if (this->size > 1)
    {
        // swap to keep packed

        Entity replace_entity = this->iToE.at(this->size - 1);
        T replace_data = this->arr.at(this->size - 1);

        this->arr.at(old_index) = replace_data;

        this->eToI.at(replace_entity) = old_index;
        this->iToE.at(old_index) = replace_data;

        this->eToI.erase(old_entity);
        this->iToE.erase(this->size - 1);
    }
    else
    {
        this->eToI.erase(old_entity);
        this->iToE.erase(old_index);
    }

    this->size--;

    return;
}