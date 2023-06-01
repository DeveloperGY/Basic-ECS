#define MAX_ENTITIES 1000

#include "entity.h"

int main(void)
{
    Entity player = Entities::gen_entity();
    Entities::recycle(player);
    return 0;
}