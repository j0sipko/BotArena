#include "Block1.h"

Block1::Block1()
{
    setName("Block1");
    setAngle(getPi()/2);
    setAnimation("textures/object1.png",50,50,100,1,1);
    setCollisionWidthHeight(28, 28);
    movePoint(+9, 9);
}

Block1::~Block1()
{
    //dtor
}
