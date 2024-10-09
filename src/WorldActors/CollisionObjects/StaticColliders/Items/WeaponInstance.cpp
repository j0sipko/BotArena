#include "WeaponInstance.h"
#include "Player.h"

WeaponInstance::WeaponInstance()
{
    fullAuto = false;
    automatic = false;
    //ctor
}

WeaponInstance::~WeaponInstance()
{
    //dtor
}

void WeaponInstance::equipPlayer(Actor *player)
{
    Player* tempPlayer = dynamic_cast<Player*>(player);
    if (tempPlayer==NULL)
        return;
    tempPlayer->setWeapon(this);
    //dynamic_cast<Player*>(getWorld()->getPlayer())->setWeapon(this);
}

void WeaponInstance::equip(Actor *player)
{
    Player* tempPlayer = dynamic_cast<Player*>(player);
    if (tempPlayer==NULL)
        return;
    if (tempPlayer->getWeapon() !=NULL)
        tempPlayer->getWeapon()->unequip(player);
    Equipable::equip(player);
}

int WeaponInstance::getDamage()
{
    return damage;
}

int WeaponInstance::getRange()
{
    return range;
}

int WeaponInstance::getBulletSpeed()
{
    return bulletSpeed;
}

void WeaponInstance::setStats(int newDamage, int newRange, int newBulletSpeed, int newFireRate)
{
    fireRate = newFireRate;
    damage = newDamage;
    range = newRange;
    bulletSpeed = newBulletSpeed;
}

int WeaponInstance::getBulletCount()
{
    return bulletCount;
}

int WeaponInstance::getFireRate()
{
    return fireRate;
}

void WeaponInstance::setBulletCount(int newCount)
{
    bulletCount = newCount;
}

bool WeaponInstance::isFullAuto()
{
    return fullAuto;
}

void WeaponInstance::toggle()
{
    if (automatic)
        fullAuto = !fullAuto;
}

void WeaponInstance::setAutomatic(bool isAuto)
{
    automatic = isAuto;
}

bool WeaponInstance::isAutomatic()
{
    return automatic;
}

