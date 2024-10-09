#include "Gun.h"
#include "Player.h"

Gun::Gun()
{
    setName("Gun");
    priority = 1;
    setAngle(getPi()/2);
    setAnimation("textures/gun2.png",25,25,100,1,1);
    stopAnimation();
    setAutomatic(true);
    setStats(15, 550, 4, 10);
    setBulletCount(50);
    setPickableBy("Player");
    /*setName("ahoj");
    if (getName().compare("ahoj")==0)
        printf("XXXXXXXXXXXXXXXXXXXXx ahoj xXXXXXXXXXXXXXXXXXXXX!\n\n\n");
    */
}

Gun::~Gun()
{
    //dtor
}

void Gun::use(Actor *player)
{
    Player* tempPlayer = dynamic_cast<Player*>(player);
    if (tempPlayer==NULL)
        return;
    if (isEquipped())
        tempPlayer->setPlayerAnimationNG();
        else tempPlayer->setPlayerAnimation();
        /*
        dynamic_cast<Player*>(getWorld()->getPlayer())->setGun(0);
        else dynamic_cast<Player*>(getWorld()->getPlayer())->setGun(1);
        */
}





