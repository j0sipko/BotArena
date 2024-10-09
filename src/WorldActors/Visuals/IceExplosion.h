#ifndef ICEEXPLOSION_H
#define ICEEXPLOSION_H
#include "WorldActor.h"

class IceExplosion : public WorldActor
{
    public:
        IceExplosion();
        virtual ~IceExplosion();
        void act();

    protected:

    private:
        bool deleteExp;
};

#endif // ICEEXPLOSION_H
