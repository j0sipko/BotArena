#ifndef SMALLEXPLOSION_H
#define SMALLEXPLOSION_H
#include "WorldActor.h"

class SmallExplosion : public WorldActor
{
    public:
        SmallExplosion();
        virtual ~SmallExplosion();
        void act();

    protected:

    private:
        bool deleteExp;
};

#endif // SMALLEXPLOSION_H
