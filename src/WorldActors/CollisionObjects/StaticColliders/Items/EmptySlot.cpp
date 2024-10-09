#include "EmptySlot.h"

EmptySlot::EmptySlot()
{
    setName("EmptySlot");
    setAnimation("textures/inventorySlot.png",100,100,70,1,1);
    //ctor
}

EmptySlot::~EmptySlot()
{
    //dtor
}

void EmptySlot::use()
{

}
