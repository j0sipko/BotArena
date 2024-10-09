#ifndef SOLDIER_H
#define SOLDIER_H
#include "ArenaPlayer.h"


class Soldier : public ArenaPlayer
{
    public:
        Soldier();
        virtual ~Soldier();
        void actFunction();

    protected:

    private:
        void turnAt();
        void setAngle();
        void setAnimation();
        void set_position();
};

#endif // SOLDIER_H
