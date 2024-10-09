#ifndef BULLET_H
#define BULLET_H
#include "WeaponInstance.h"
#include "Creature.h"
#include "Player.h"

using namespace std;

class Bullet : public Creature
{
    public:
        Bullet();
        virtual ~Bullet();
        bool getDestroyed();
        void act();
        void setDestroyed(bool x);
        WeaponInstance* getGun();
        void setGun(WeaponInstance *newGun);
        bool moveForward(float distance, string explosionName);
        void setPlayer(Player *newPlayer);
        void initiate();
        void setExplosionName(string newName);
        virtual void setBonuses(Actor* creature);

    protected:

    private:
        string explosionName;
        WeaponInstance* gun;
        Player *player;
        bool destroyed;
        float startX, startY;
};

#endif // BULLET_H


