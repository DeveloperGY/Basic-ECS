#ifndef ENTITY_H
#define ENTITY_H

#include <queue>

#ifndef MAX_ENTITIES
#define MAX_ENTITIES 100
#endif

typedef int Entity;

class Entities
{
    private:
        static std::queue<Entity> recycle_bin;
        static int next_id;
        static int alive_count;

    public:
        static int count();
        static Entity gen_entity();
        static void recycle(Entity &e);
};

#endif