#define MAX_ENTITIES 1000

#include "entity.h"
#include "component.h"

#include <iostream>

struct Position
{
    float x;
    float y;
    float z;
};

struct Velocity
{
    float dx;
    float dy;
    float dz;
};

int main(void)
{
    Components::register_component<Position>();
    Components::register_component<Velocity>();

    Entity player = Entities::gen_entity();
    Entities::recycle(player);

    return 0;
}