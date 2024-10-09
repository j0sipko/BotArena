#include "Item.h"
#include "Player.h"
#include "Equipable.h"
#include "Medipack.h"

Item::Item()
{
    setName("Item");
    owner = NULL;
    pickableBy = "noone";
    //ctor
}

void Item::use(Actor *player)
{

}

string Item::getPickableBy()
{
    return pickableBy;
}

void Item::setPickableBy(string newPickableBy)
{
    pickableBy = newPickableBy;
}

bool Item::isActorPlayer(Actor *actor)
{
    if ((actor->getName().compare(pickableBy) == 0))
        return true;
    else return false;
}

void Item::act()
{
    Actor *temp = getWorld()->getFirstActor();
    while (temp!=NULL)
    {
        if (isActorPlayer(temp))
        {
            if (checkCollisionWithObject(dynamic_cast<CollisionObject*>(temp)))
            {
                Player *tempPlayer = dynamic_cast<Player*>(temp);
                if (tempPlayer->getInventory()->isInventoryFull())
                    return;
                if (dynamic_cast<Medipack*>(this) ==NULL)
                {
                    setOwner(temp);
                    tempPlayer->getInventory()->addItem(this);
                    //dynamic_cast<Player*>(temp)->getInventory()->addItem(this);
                    if (dynamic_cast<Equipable*>(this) != NULL)
                        dynamic_cast<Equipable*>(this)->equip(temp);
                        else use(temp);
                    getWorld()->removeItem(this);
                }
                else
                {
                    if (dynamic_cast<Player*>(temp)->getHP() < dynamic_cast<Player*>(temp)->getFullHP())
                    {
                        use(temp);
                        getWorld()->removeActor(this);
                    }
                }

            }

        }
        temp = getWorld()->getNextActor();
    }

}

void Item::drawItem()
{
    float tempW = getWidth();
    float tempH = getHeight();
    setSize(90, 90);
    drawImage();
    setSize(tempW, tempH);

}

Item::~Item()
{
    //dtor
}

void Item::setOwner(Actor* newOwner)
{
    owner = newOwner;
}

Actor* Item::getOwner()
{
    return owner;
}

/*void Item::setInventory(Inventory newInventory)
{
    inventory = newInventory;
}

Inventory* Item::getInventory()
{
    return inventory;
}*/




