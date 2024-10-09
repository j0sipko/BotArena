#ifndef EMPTYSLOT_H
#define EMPTYSLOT_H
#include "Item.h"


class EmptySlot : public Item
{
    public:
        EmptySlot();
        virtual ~EmptySlot();
        void use();

    protected:

    private:
};

#endif // EMPTYSLOT_H
