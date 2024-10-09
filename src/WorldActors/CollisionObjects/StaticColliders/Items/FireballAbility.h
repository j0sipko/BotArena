#ifndef FIREBALL_H
#define FIREBALL_H
#include "WeaponInstance.h"

class FireballAbility : public WeaponInstance
{
    public:
        FireballAbility();
        virtual ~FireballAbility();
        void use();

    protected:

    private:
};

#endif // FIREBALL_H
