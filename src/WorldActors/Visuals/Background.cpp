#include "Background.h"

Background::Background()
{
    setName("Background");
    priority = 0;
    setAngle(getPi()/2);
    setAnimation("textures/background.png",1366,768,100,1,1);
    //ctor
}

Background::~Background()
{
    //dtor
}
