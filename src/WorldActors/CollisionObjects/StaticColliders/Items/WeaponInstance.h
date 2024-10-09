#ifndef WEAPONINSTANCE_H
#define WEAPONINSTANCE_H
#include "Equipable.h"


class WeaponInstance : public Equipable
{
    public:
        WeaponInstance();
        bool isFullAuto();
        void toggle();
        void setAutomatic(bool isAuto);
        bool isAutomatic();
        virtual ~WeaponInstance();
        void equipPlayer(Actor *player);
        void equip(Actor *player);
        int getDamage();
        int getRange();
        int getFireRate();
        int getBulletSpeed();
        void setStats(int newDamage, int newRange, int newBulletSpeed, int newFireRate);
        int getBulletCount();
        void setBulletCount(int newCount);

    protected:

    private:
        int fireRate;
        int damage;
        int range;
        int bulletSpeed;
        int bulletCount;
        bool fullAuto;
        bool automatic;
};

#endif // WEAPONINSTANCE_H
