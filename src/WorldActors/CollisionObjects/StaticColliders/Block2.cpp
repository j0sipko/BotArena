#include "Block2.h"

Block2::Block2()
{
    setName("Block2");
    setAngle(getPi()/2);
    setAnimation("textures/object2.png",40,40,100,1,1);
    setCollisionWidthHeight(35, 35);
    //movePoint(-9, 9);
}

Block2::~Block2()
{
    //dtor
}
