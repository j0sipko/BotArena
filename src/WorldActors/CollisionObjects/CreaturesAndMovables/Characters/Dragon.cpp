#include "Dragon.h"
#include "Fireball.h"
#include "Wizard.h"

Dragon::Dragon()
{
    setObjectType(Air);
    setName("Dragon");
    priority = 4;
    setAngle(getPi()/2);
    setAnimation("textures/dragon.png",80,80,40,10,1);
    //setAnimation("textures/dragonWalking.png",80,80,100,5,1);
    setCollisionWidthHeight(55, 55);
    startAnimation();
    setHP(150);
    setMaxHP(150);
    //setDrawAngleDifference(getPi()/2);
    setSight(450, 60);
    timerRoF=0;
    setPingPong(false);
    setColor("RED");
    setTeam(2);
}

Dragon::~Dragon()
{
    //dtor
}

Actor* Dragon::getDestinationObject()
{
    std::vector<Actor*> actors = getWorld()->getActors();
    Actor* tempActor;
    Actor* returnActor = NULL;
    for (int i =0; i< actors.size(); i++)
    {
        tempActor = actors.at(i);
        if (dynamic_cast<Player*>(tempActor)!=NULL && tempActor!=this)
        {
            if (returnActor!=NULL)
            {
                if (this->getDistanceOf(tempActor)< this->getDistanceOf(returnActor))
                    returnActor = tempActor;
            }
            else returnActor=tempActor;
        }
        else if (dynamic_cast<Wizard*>(tempActor)!=NULL)
        if (dynamic_cast<Player*>(tempActor)!=NULL && tempActor!=this)
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

void Dragon::attack(int fireRate)
{
    if (timerRoF == 0)
    {
        getWorld()->addActor("Fireball", get_X(), get_Y());
        getWorld()->removeActorAt(getWorld()->getActorCount()-1);
        Fireball* temp = dynamic_cast<Fireball*>(getWorld()->getActorAt(getWorld()->getActorCount()-1));
        /*printf("actorCount = %d\n", getWorld()->getActorCount());
        printf("lastActorIndex = %d\n", getWorld()->getIndexOf(getWorld()->getActorAt(getWorld()->getActorCount()-1)));*/
        temp->setPlayer(this);
        temp->initiate();
        timerRoF+= fireRate;
    }

}

void Dragon::act()
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
    if (getDistanceOf(getDestinationObject()) > 60)
    {
        if (isPathClear(0,1))
            moveForward(1);
        else if (isPathClear(90,1) && !(lastMove==movingRight && isPathClear(-90,1)))
            moveLeft(1);
        else if (isPathClear(-90,1))
            moveRight(1);
    };

    Creature::act();
}
