#include "SniperRifle.h"
#include "Player.h"

SniperRifle::SniperRifle()
{
    setName("SniperRifle");
    priority = 1;
    setAngle(getPi()/2);
    setAnimation("textures/Sniper.png",35,35,100,1,1);
    stopAnimation();
    setStats(50, 1000, 10, 50);
    setBulletCount(20);
    setAutomatic(false);
    setPickableBy("Player");
}

SniperRifle::~SniperRifle()
{
    //dtor
}

void SniperRifle::use(Actor *player)
{
    Player* tempPlayer = dynamic_cast<Player*>(player);
    if (tempPlayer==NULL)
        return;
    if (isEquipped())
        tempPlayer->setPlayerAnimationNG();
        else tempPlayer->setPlayerAnimationSniper();
        /*
        dynamic_cast<Player*>(getWorld()->getPlayer())->setGun(0);
        else dynamic_cast<Player*>(getWorld()->getPlayer())->setGun(1);
        */
}
