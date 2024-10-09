#ifndef FIREBLAST_H
#define FIREBLAST_H
#include "Bullet.h"


class FireBlast : public Bullet
{
    public:
        FireBlast();
        virtual ~FireBlast();
        void setBonuses(Actor* creature);

    protected:

    private:
};

#endif // FIREBLAST_H
