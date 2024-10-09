#include "Helmet.h"

Helmet::Helmet()
{
    setName("Helmet");
    priority = 1;
    setAngle(getPi()/2);
    setAnimation("textures/Helmet.png",25,25,100,1,1);
    setBonuses(10,10,25);
    setPercentBonuses(10,10);
    setPickableBy("Player");
}

Helmet::~Helmet()
{
    //dtor
}



