#ifndef MEDIPACK_H
#define MEDIPACK_H
#include "Item.h"

class Medipack : public Item
{
    public:
        Medipack();
        virtual ~Medipack();
        void use(Actor *player);

    protected:

    private:
};

#endif // MEDIPACK_H
