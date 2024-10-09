#ifndef ITEM_H
#define ITEM_H
#include "CollisionObject.h"
using namespace std;

class Item : public CollisionObject
{
    public:
        Item();
        virtual ~Item();
        void act();
        void drawItem();
        virtual void use(Actor *player);
        bool isActorPlayer(Actor *actor);
        void setOwner(Actor* newOwner);
        Actor* getOwner();
        string getPickableBy();
        void setPickableBy(string newPickableBy);
        /*void setInventory(Inventory *newInventory);
        Inventory* getInventory();*/

    protected:

    private:
        Actor *owner;
        string pickableBy;
        //Inventory *inventory;
};

#endif // ITEM_H
