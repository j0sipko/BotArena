#ifndef ICEBLAST_H
#define ICEBLAST_H
#include "Bullet.h"


class IceBlast : public Bullet
{
    public:
        IceBlast();
        virtual ~IceBlast();
        void setBonuses(Actor* creature);

    protected:

    private:
};

#endif // ICEBLAST_H
