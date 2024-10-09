#include "StaffRed.h"
#include "Wizard.h"

StaffRed::StaffRed()
{
    setName("StaffRed");
    priority = 1;
    setAngle(getPi()/2);
    setAnimation("textures/StaffRed.png",40,40,100,1,1);
    stopAnimation();
    setAutomatic(false);
    setStats(25, 600, 5, 50);
    setBulletCount(50);
    setPickableBy("Wizard");
}

StaffRed::~StaffRed()
{
    //dtor
}

void StaffRed::use(Actor *player)
{
    Wizard* tempPlayer = dynamic_cast<Wizard*>(player);
    if (tempPlayer==NULL)
        return;
    if (isEquipped())
        tempPlayer->setWizardAnimationNG();
        else tempPlayer->setWizardAnimationRedStaff();
        /*
        dynamic_cast<Player*>(getWorld()->getPlayer())->setGun(0);
        else dynamic_cast<Player*>(getWorld()->getPlayer())->setGun(1);
        */
}
