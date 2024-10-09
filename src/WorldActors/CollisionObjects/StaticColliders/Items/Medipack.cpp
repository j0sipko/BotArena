#include "Medipack.h"
#include "Player.h"

Medipack::Medipack()
{
    setName("Medipack");
    priority = 1;
    setAngle(getPi()/2);
    setAnimation("textures/medipack.png",15,15,100,1,1);
    stopAnimation();
    setPickableBy("Player");
    //ctor
}

Medipack::~Medipack()
{
    //dtor
}

void Medipack::use(Actor *player)
{
    printf("healing\n\n");
    Player* tempPlayer = dynamic_cast<Player*>(player);
    if (tempPlayer==NULL)
        return;
    printf("healed\n\n");
    tempPlayer->heal(25);
}
