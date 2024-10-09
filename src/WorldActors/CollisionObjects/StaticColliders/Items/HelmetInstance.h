#ifndef HELMETINSTANCE_H
#define HELMETINSTANCE_H
#include "Equipable.h"


class HelmetInstance : public Equipable
{
    public:
        HelmetInstance();
        virtual ~HelmetInstance();
        void equipPlayer(Actor *player);
        void equip(Actor *player);

    protected:

    private:
};

#endif // HELMETINSTANCE_H
