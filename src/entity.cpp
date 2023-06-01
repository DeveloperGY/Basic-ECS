#include "entity.h"

std::queue<Entity> Entities::recycle_bin = std::queue<Entity>();
int Entities::next_id = 0;
int Entities::alive_count = 0;

int Entities::count()
{
    return Entities::alive_count;
}

void Entities::recycle(Entity &e)
{
    if (e >= 0)
    {
        Entities::recycle_bin.push(e);
        Entities::alive_count--;
        e = -1;
    }
}

Entity Entities::gen_entity()
{
    if (alive_count >= MAX_ENTITIES)
    {
        return -1;
    }

    Entities::alive_count++;

    if (Entities::recycle_bin.size() > 0)
    {
        Entity id = Entities::recycle_bin.front();
        Entities::recycle_bin.pop();
        return id;
    }

    return Entities::next_id++;
}