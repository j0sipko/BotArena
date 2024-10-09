#include "Ability.h"

Ability::Ability()
{
    isReady = true;
    cooldown = 0;
    //ctor
}

Ability::~Ability()
{
    //dtor
}

float Ability::getCooldown()
{
    return cooldown;
}

void Ability::setCooldown(float newCD)
{
    cooldown = newCD;
}

void Ability::act()
{
    if (!isReady)
    {
        time_t tempTime;
        time(&tempTime);
        double diff = difftime(cdTime, tempTime);
        if ((int)diff > cooldown)
            isReady=true;
    }
}

void Ability::use()
{
    if (isReady)
    {
        time(&cdTime);
        isReady = false;
    }
}


