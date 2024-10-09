#ifndef SNIPERRIFLE_H
#define SNIPERRIFLE_H
#include "WeaponInstance.h"


class SniperRifle : public WeaponInstance
{
    public:
        SniperRifle();
        virtual ~SniperRifle();
        void use(Actor *player);

    protected:

    private:
};

#endif // SNIPERRIFLE_H
