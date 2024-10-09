#ifndef ACTOR_H
#define ACTOR_H
#include "Actor.h"
#include "World.h"
#include <vector>

class WorldActor : public Actor
{
    public:
        WorldActor();
        virtual ~WorldActor();
        void setWorld(World *newWorld);
        World* getWorld();
        bool isMouseOn();

    private:
        World* world;
};

#endif // ACTOR_H
