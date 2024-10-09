#include "Scope.h"

Scope::Scope()
{
    paused = false;
    setName("Scope");
    priority = 5;
    setAngle(getPi()/2);
    setAnimation("textures/scope.png",50,50,100,1,1);
}

Scope::~Scope()
{
    //dtor
}

void Scope::act()
{
    if (getWorld()->isPaused() && !paused)
    {
        setAnimation("textures/hand.png",70,70,100,1,1);
        paused = true;
    }
    else if (!getWorld()->isPaused() && paused)
    {
        setAnimation("textures/scope.png",50,50,100,1,1);
        paused = false;
    }

    set_position(getWorld()->getCameraX()[0] - getWorld()->maxX/2 + getWorld()->getEvent()->mouseX,
                 getWorld()->getCameraY()[0] - getWorld()->maxY/2 + getWorld()->getEvent()->mouseY);
}

void Scope::drawImage()
{
    if (!getWorld()->isDrawing())
    {
        act();
        Actor::drawImage();
    }
}




