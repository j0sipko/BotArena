#ifndef STAFFBLUE_H
#define STAFFBLUE_H
#include "WeaponInstance.h"

class StaffBlue : public WeaponInstance
{
    public:
        StaffBlue();
        virtual ~StaffBlue();
        void use(Actor *player);

    protected:

    private:
};

#endif // STAFFBLUE_H
