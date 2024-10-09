#include "IceBlast.h"
#include "Player.h"

IceBlast::IceBlast()
{
    setAnimation("textures/IceBlast.png",25, 25, 100, 1, 1);
    setCollisionWidthHeight(3, 3);
    stopAnimation();
    setName("IceBlast");
    setExplosionName("IceExplosion");
    //ctor
}

IceBlast::~IceBlast()
{
    //dtor
}

void IceBlast::setBonuses(Actor* creature)
{
    Player* tempPlayer = dynamic_cast<Player*>(creature);
    if (tempPlayer != NULL)
    {
        tempPlayer->setBonuses(-50, 0, 5);
    }
}
