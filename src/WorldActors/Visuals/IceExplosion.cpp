#include "IceExplosion.h"

IceExplosion::IceExplosion()
{
    setName("IceExplosion");
    priority = 4;
    setAngle(getPi()/2);
    setAnimation("textures/iceExplosion.png",30,30,40,4,1);
    startAnimation();
    setPingPong(false);
    deleteExp = false;
    setCurXY(1,1);
}

IceExplosion::~IceExplosion()
{
    //dtor
}


void IceExplosion::act()
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
