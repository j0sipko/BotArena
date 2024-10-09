#include "Fireball.h"
#include <math.h>
#include "Player.h"

Fireball::Fireball()
{
    setObjectType(GroundAndAir);
    priority = 2;
    destroyed=false;
    setAnimation("textures/fireball.png",30, 18, 100, 1, 1);
    setCollisionWidthHeight(3, 3);
    stopAnimation();
    setName("Fireball");
    range = 350;
    damage = 3;
    speed = 5;
}

Fireball::~Fireball()
{
    //dtor
}


void Fireball::act()
{
    if ((get_X()-startX)*(get_X()-startX) + (get_Y()-startY)*(get_Y()-startY) > range*range)
    {
        destroyed=true;
        getWorld()->removeActor(this);
    }
    if (!destroyed)
    {
        moveForward(speed, "daco");
        //set_position(get_X()+gun->getBulletSpeed()*sin(getAngle()+getPi()/2), get_Y()+gun->getBulletSpeed()*cos(getAngle()+getPi()/2));
    }
}

bool Fireball::getDestroyed()
{
    return destroyed;
}

void Fireball::setDestroyed(bool x)
{
    destroyed=x;
}

void Fireball::initiate()
{
    setAngle(player->getAngle());
    set_position(player->get_X(), player->get_Y());
    startX = get_X();
    startY = get_Y();
    float rfp = 3 + sqrt((player->getCollisionHeight()/2) * (player->getCollisionHeight()/2)
        + (player->getCollisionWidth()/2) * (player->getCollisionWidth()/2));
        set_position(get_X()+rfp*sin(getAngle()+getPi()/2), get_Y()+rfp*cos(getAngle()+getPi()/2));
}

bool Fireball::moveForward(float distance, string explosionName)
{
    Actor* tempActor;
    tempActor = Creature::moveForward(distance);
    if (tempActor !=NULL)
    {
        Creature* tempCreature = dynamic_cast<Creature*>(tempActor);
        if (tempCreature!=NULL)
            tempCreature->doDamage(damage);
        getWorld()->removeActor(this);
        return false;
    }
    return true;

    /*
    if (Creature::moveForward(distance))
    {
        if (dynamic_cast<Creature*>(checkCollisionO()) != NULL)
            dynamic_cast<Creature*>(checkCollisionO())->doDamage(damage);
        getWorld()->removeActor(this);
        checkCollisionO();
    }
    return NULL;
    */
}

void Fireball::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}
