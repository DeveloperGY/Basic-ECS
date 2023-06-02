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

int main(void)
{
    Component position = Components::register_component<Position>();

    Entity player = Entities::gen_entity();
    Entities::recycle(player);

    return 0;
}