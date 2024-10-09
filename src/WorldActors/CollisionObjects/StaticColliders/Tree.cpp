#include "Tree.h"

Tree::Tree()
{
    setName("Tree");
    setAngle(getPi()/2);
    setAnimation("textures/tree2.png",45,45,100,1,1);
    setCollisionWidthHeight(40, 40);
    //movePoint(0, 22);
}

Tree::~Tree()
{
    //dtor
}
