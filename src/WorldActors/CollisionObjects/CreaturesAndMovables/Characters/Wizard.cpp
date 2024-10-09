#include "Wizard.h"
#include "Fireball.h"
#include "IceBlast.h"
#include "Dragon.h"
#include "Player.h"
#include "StaffBlue.h"
#include "StaffRed.h"
#include <vector>

Wizard::Wizard()
{
    setSight(500, 50);
    setHP(100);
    setMaxHP(100);
    //maxHP = 100;
    setAnimation("textures/MageBlueNG.png",55,55,100,5,1);
    setCollisionWidthHeight(35, 35);
    setName("Wizard");
    setColor("BLACK");

    startAnimation();
    setHP(150);
    setMaxHP(150);
    //setDrawAngleDifference(getPi()/2);
    setSight(450, 60);
    timerRoF=0;
    setPingPong(false);
    setTeam(3);
}

Actor* Wizard::getDestinationObject()
{
    std::vector<Actor*> actors = getWorld()->getActors();
    Actor* tempActor;
    Actor* returnActor = NULL;
    WeaponInstance* tempWeapon;
    for (int i =0; i< actors.size(); i++)
    {
        tempActor = actors.at(i);
        if (getWeapon()==NULL)
        {
            tempWeapon = dynamic_cast<WeaponInstance*>(tempActor);
            if (tempWeapon!=NULL && tempWeapon->getPickableBy().compare("Wizard")==0)
            {
                if (returnActor!=NULL)
                {
                    if (this->getDistanceOf(tempActor)< this->getDistanceOf(returnActor))
                        returnActor = tempActor;
                }
                else returnActor=tempActor;

            }

        }
        else if (dynamic_cast<Player*>(tempActor)!=NULL && tempActor->getName().compare(getName())!=0)
        {
            if (returnActor!=NULL)
            {
                if (this->getDistanceOf(tempActor)< this->getDistanceOf(returnActor))
                    returnActor = tempActor;
            }
            else returnActor=tempActor;
        }
        else if (dynamic_cast<Dragon*>(tempActor)!=NULL)
        {
            if (returnActor!=NULL)
            {
                if (this->getDistanceOf(tempActor)< this->getDistanceOf(returnActor))
                    returnActor = tempActor;
            }
            else returnActor=tempActor;
        }
    }
    return returnActor;
}

void Wizard::setWizardAnimationNG()
{
    setAnimation("textures/MageBlue.png",55,55,100,5,1);
}

void Wizard::setWizardAnimationBlueStaff()
{
    setAnimation("textures/MageBlueBlueStaff.png",55,55,100,5,1);
}

void Wizard::setWizardAnimationRedStaff()
{
    setAnimation("textures/MageBlueRedStaff.png",55,55,100,5,1);
}

Wizard::~Wizard()
{
    //dtor
}

void Wizard::attack(int fireRate)
{
    if (getWeapon()!=NULL && getWeapon()->isEquipped() && (timerRoF==0))
    {
        if (dynamic_cast<StaffBlue*>(getWeapon()) != NULL)
            getWorld()->addActor("IceBlast", get_X(), get_Y());
        else if (dynamic_cast<StaffRed*>(getWeapon()) != NULL)
            getWorld()->addActor("FireBlast", get_X(), get_Y());
        getWorld()->removeActorAt(getWorld()->getActorCount()-1);
        Bullet* temp = dynamic_cast<Bullet*>(getWorld()->getActorAt(getWorld()->getActorCount()-1));
        temp->setPlayer(this);
        temp->initiate();
        WeaponInstance *tempWeapon = dynamic_cast<WeaponInstance*>(getWeapon());
        timerRoF+= tempWeapon->getFireRate();
    }
    /*if (timerRoF == 0)
    {
        getWorld()->addActor("Fireball", get_X(), get_Y());
        getWorld()->removeActorAt(getWorld()->getActorCount()-1);
        Fireball* temp = dynamic_cast<Fireball*>(getWorld()->getActorAt(getWorld()->getActorCount()-1));
        temp->setPlayer(this);
        temp->initiate();
        timerRoF+= fireRate;
    }*/

}

void Wizard::act()
{
    //moveForward(2);

    if (getDestinationObject() == NULL)
    {
        Creature::act();
        return;
    }


    if (getDistanceOf(getDestinationObject()) < 350)
    {
        attack(10);
    }
    if (timerRoF>0)
        timerRoF--;

    turnAt(getDestinationObject()->get_X(), getDestinationObject()->get_Y());
    int distance=0;
    if (dynamic_cast<WeaponInstance*>(getDestinationObject())==NULL)
        distance = 60;
    if (getDistanceOf(getDestinationObject()) > distance)
    {
        if (isPathClear(0,1))
            moveForward(1);
        else if (isPathClear(90,1) && !(lastMove==movingRight && isPathClear(-90,1)))
            moveLeft(1);
        else if (isPathClear(-90,1))
            moveRight(1);
    }


    Creature::act();
}
