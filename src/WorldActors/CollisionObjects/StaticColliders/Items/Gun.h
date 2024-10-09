#ifndef GUN_H
#define GUN_H
#include "WeaponInstance.h"

class Gun : public WeaponInstance
{
    public:
        Gun();
        virtual ~Gun();
        void use(Actor *player);

    private:

};

#endif // GUN_H
