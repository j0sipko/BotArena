#ifndef ABILITY_H
#define ABILITY_H
#include <ctime>
#include <iostream>
#include "WorldActor.h"

class Ability : public WorldActor
{
    public:
        Ability();
        virtual ~Ability();
        void act();
        void setCooldown(float newCD);
        float getCooldown();
        void use();

    protected:

    private:
        int cooldown;
        bool isReady;
        time_t cdTime;

};

#endif // ABILITY_H
