#ifndef FIREBALL_H
#define FIREBALL_H
#include "Creature.h"
#include "Player.h"

class Fireball : public Creature
{
    public:
        Fireball();
        virtual ~Fireball();
        bool getDestroyed();
        void act();
        void setDestroyed(bool x);
        bool moveForward(float distance, string explosionName);
        void setPlayer(Player *newPlayer);
        void initiate();

    protected:

    private:
        Player *player;
        bool destroyed;
        float startX, startY;
        int range, damage, speed;
};

#endif // FIREBALL_H
