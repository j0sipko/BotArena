#include "Bullet.h"
#include <math.h>
#include "Player.h"

Bullet::Bullet()
{
    setObjectType(GroundAndAir);
    priority = 2;
    destroyed=false;
    setAnimation("textures/bullet2.png",20, 12, 100, 1, 1);
    setCollisionWidthHeight(1, 1);
    stopAnimation();
    setName("Bullet");
    explosionName = "SmallExplosion";
}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::act()
{
    if ((get_X()-startX)*(get_X()-startX) + (get_Y()-startY)*(get_Y()-startY) > gun->getRange()*gun->getRange())
    {
        destroyed=true;
        getWorld()->removeActor(this);
    }
    if (!destroyed)
    {
        moveForward(gun->getBulletSpeed(), explosionName);
        //set_position(get_X()+gun->getBulletSpeed()*sin(getAngle()+getPi()/2), get_Y()+gun->getBulletSpeed()*cos(getAngle()+getPi()/2));
    }
}

bool Bullet::getDestroyed()
{
    return destroyed;
}

void Bullet::setDestroyed(bool x)
{
    destroyed=x;
}

WeaponInstance* Bullet::getGun()
{
    return gun;
}

void Bullet::setGun(WeaponInstance *newGun)
{
    gun = newGun;
}

void Bullet::initiate()
{
    setGun(dynamic_cast<WeaponInstance*>(player->getWeapon()));
    setAngle(player->getAngle());
    set_position(player->get_X(), player->get_Y());
    startX = get_X();
    startY = get_Y();
    float rfp = 3 + sqrt((player->getHeight()/2) * (player->getHeight()/2)
        + (player->getWidth()/2) * (player->getWidth()/2));
        set_position(get_X()+rfp*sin(getAngle()+getPi()/2), get_Y()+rfp*cos(getAngle()+getPi()/2));
}

bool Bullet::moveForward(float distance, string explosionName)
{
    //set_position(get_X()+(cos(getAngle())*distance), get_Y()-(sin(getAngle())*distance));
    Actor* tempActor;
    tempActor = Creature::moveForward(distance);
    if (tempActor !=NULL)
    {
        Creature* tempCreature = dynamic_cast<Creature*>(tempActor);
        if (tempCreature!=NULL)
        {
            tempCreature->doDamage(gun->getDamage());
            setBonuses(tempActor);
        }

        getWorld()->addActor(explosionName, get_X(), get_Y());
        getWorld()->removeActor(this);
        return false;
    }
    return true;
}

void Bullet::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}

void Bullet::setExplosionName(string newName)
{
    explosionName = newName;
}

void Bullet::setBonuses(Actor* creature)
{

}

