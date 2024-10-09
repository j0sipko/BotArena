#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include "WorldActor.h"
#include "Creature.h"


class HealthBar : public WorldActor
{
    public:
        HealthBar();
        virtual ~HealthBar();
        void drawImage();
        void setCreature(Creature *newCreature);
        void afterWorldSetter();

    protected:

    private:
        string creatureName;
        int height;
        int width;
        int maxX;
        int maxY;
        Creature *creature;
};

#endif // HEALTHBAR_H
