#ifndef STAFFRED_H
#define STAFFRED_H
#include "WeaponInstance.h"

class StaffRed : public WeaponInstance
{
    public:
        StaffRed();
        virtual ~StaffRed();
        void use(Actor *player);

    protected:

    private:
};

#endif // STAFFRED_H
