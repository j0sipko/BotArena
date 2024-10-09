#include "StaffBlue.h"
#include "Wizard.h"

StaffBlue::StaffBlue()
{
    setName("StaffBlue");
    priority = 1;
    setAngle(getPi()/2);
    setAnimation("textures/StaffBlue.png",40,40,100,1,1);
    stopAnimation();
    setAutomatic(false);
    setStats(40, 350, 3, 80);
    setBulletCount(50);
    setPickableBy("Wizard");
}

StaffBlue::~StaffBlue()
{
    //dtor
}

void StaffBlue::use(Actor *player)
{
    Wizard* tempPlayer = dynamic_cast<Wizard*>(player);
    if (tempPlayer==NULL)
        return;
    if (isEquipped())
        tempPlayer->setWizardAnimationNG();
        else tempPlayer->setWizardAnimationBlueStaff();
        /*
        dynamic_cast<Player*>(getWorld()->getPlayer())->setGun(0);
        else dynamic_cast<Player*>(getWorld()->getPlayer())->setGun(1);
        */
}
