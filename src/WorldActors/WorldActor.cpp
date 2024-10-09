#include "WorldActor.h"
#include "World.h"

WorldActor::WorldActor()
{
    world = NULL;
    //ctor
}

WorldActor::~WorldActor()
{
    //dtor
}

void WorldActor::setWorld(World *newWorld)
{
    world = newWorld;
}

World* WorldActor::getWorld()
{
    return &world[0];
}

bool WorldActor::isMouseOn()
{
    if (getWorld()->getEvent()->mouseX > get_X()-getWidth()/2 && getWorld()->getEvent()->mouseX < get_X()+getWidth()/2 &&
        getWorld()->getEvent()->mouseY > get_Y()-getHeight()/2 && getWorld()->getEvent()->mouseY < get_Y()+getHeight()/2)
        return true;
    else return false;
}
