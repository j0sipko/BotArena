#ifndef PLAYER_H
#define PLAYER_H
#include "Creature.h"
#include "Inventory.h"
#include <time.h>

class Player : public Creature
{
    private:
        float damage;
        int numberOfGuns;
        int *ammunition;
        int stamina, maxStamina, bonusStamina;
        int percentBonusHP, percentBonusStamina;
        float rateOfFire, timerRoF;
        bool shot;
        bool autoFire;
        int range;
        int currentGun;
        Inventory* inventory;
        Equipable* helmet;
        Equipable* weapon;
        int state;
        int team;
        int speedBonus;
        int dps;
        double bonusTime;
        time_t startTime;
        int lastSecond;


    public:
        Player();
        int getTeam();
        void setTeam(int newTeam);
        virtual ~Player();
        int getGun();
        void setHelmet(Equipable *newHelmet);
        Equipable* getHelmet();
        void setWeapon(Equipable *newWeapon);
        Equipable* getWeapon();
        int getFullStamina();
        void setArmor(int newArmor);
        int getArmor();
        void setBonusHP(int newHP);
        int getBonusHP();
        void setBonusStamina(int newStamina);
        int getBonusStamina();
        int getMaxStamina();
        int getMaxHP();
        void setMaxHP(int newHP);
        void setMaxStamina(int newStamina);
        Inventory* getInventory();
        //void setAmmunitionForGun(int GunNumber, int NewAmmo);
        void setGun(int gunNumber);
        void setPlayerAnimation();
        void setPlayerAnimationNG();
        void setPlayerAnimationSniper();
        int getRange();
        void AutoFire();
        bool getAutoFire();
        bool getShotPermission();
        void giveShotPermission();
        void act();
        int getStamina();
        void setStamina(int newStamina);
        //int getAmmo();
        //void setAmmo(int newAmmo);
        bool getShot();
        void setShot(bool isShot);
        float getDamage();
        void setDamage(float newDamage);
        void setRateOfFire(float newRateOfFire);
        virtual void shoot();
        void act2();
        int getState();
        virtual Actor* moveForward(float distance);
        void setBonuses(int newSpeedBonus, int newDPS, double seconds);
        int getDPS();
        int getSpeedBonus();
        void bonusChecking();

};

#endif // PLAYER_H
