#include "FireBlast.h"

FireBlast::FireBlast()
{
    setAnimation("textures/fireball.png",40, 24, 100, 1, 1);
    setCollisionWidthHeight(2, 2);
    stopAnimation();
    setName("FireBlast");
}

FireBlast::~FireBlast()
{
    //dtor
}

void FireBlast::setBonuses(Actor* creature)
{
    Player* tempPlayer = dynamic_cast<Player*>(creature);
    if (tempPlayer != NULL)
    {
        tempPlayer->setBonuses(0, 6, 5);
    }
}
