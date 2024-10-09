#ifndef INVENTORY_H
#define INVENTORY_H
#include "WorldActor.h"
#include "Item.h"
#include "EmptySlot.h"
#include "Equipable.h"

class Inventory : public WorldActor
{
    public:
        Inventory();
        virtual ~Inventory();
        void act();
        bool isShown();
        void drawInventory();
        void addSlots(int number);
        bool addItem(Item* item);
        Item* getCurrentItem();
        void removeCurrentItem();
        void dropCurrentItem();
        void setMoney(int money);
        int getMoney();
        bool addMoney(int money);
        bool takeMoney(int money);
        void setOwner(Actor *newOwner);
        Actor* getOwner();
        bool isInventoryFull();

    protected:

    private:
        int currentMoney;
        int dropRange;
        int currentItem;
        Actor slot;
        Actor selectedItem;
        Item* items[36];
        EmptySlot emptySlot;
        bool shown;
        int slotCount;
        Actor* owner;
};

#endif // INVENTORY_H
