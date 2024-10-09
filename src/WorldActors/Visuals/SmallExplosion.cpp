#include "SmallExplosion.h"

SmallExplosion::SmallExplosion()
{
    setName("SmallExplosion");
    priority = 4;
    setAngle(getPi()/2);
    setAnimation("textures/small_explosion.png",20,20,30,4,2);
    startAnimation();
    //setDrawAngleDifference(getPi()/2);
    setPingPong(false);
    deleteExp = false;
    setCurXY(1,1);
}

SmallExplosion::~SmallExplosion()
{
    //dtor
}

void SmallExplosion::act()
{
    if (deleteExp)
    {
        getWorld()->removeActor(this);
    }
    if (isAnimationFinished())
    {
        deleteExp = true;
    }
}
