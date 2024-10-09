#ifndef DRAGON_H
#define DRAGON_H
#include "Player.h"


class Dragon : public Player
{
    public:
        Dragon();
        virtual ~Dragon();
        void act();
        void attack(int fireRate);
        Actor* getDestinationObject();
    protected:
    private:
        int timerRoF;
};

#endif // DRAGON_H
