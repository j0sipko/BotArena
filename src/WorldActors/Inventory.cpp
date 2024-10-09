#include "Inventory.h"
#include <math.h>
#include "Gun.h"
#include "ActorFactory.h"
#include "Player.h"

Inventory::Inventory()
{
    owner = NULL;
    turnOB();
    setMoney(0);
    dropRange = 50;
    setName("Inventory");
    //ctor
    //items = new Item[36];
    for (int i=0; i<36; i++)
    {
        items[i] = new EmptySlot();
    }

    slot.setAnimation("textures/inventorySlot.png",100,100,70,1,1);
    selectedItem.setAnimation("textures/selectedItem.png",100,100,70,1,1);
    slotCount = 36;
    turnOB();
    shown = false;
    setAngle(getPi()/2);
    setAnimation("textures/Inventory.png",720,760,70,1,1);
}

Inventory::~Inventory()
{
    for (int i=0; i<36; i++)
    {
        delete items[i];
    }
}

void Inventory::act()
{
    set_position(getWorld()->getCameraX()[0] + getWorld()->maxX/4+40, getWorld()->getCameraY()[0]);
    if (getWorld()->getEvent()->isKeyPressedOnce_kb_I)
        shown = !shown;
    if (getWorld()->getEvent()->isKeyPressedOnce_kb_Esc && shown)
        shown = !shown;
    /*if (getWorld()->getEvent()->isKeyPressedOnce_kb_Esc)
        shown = false;*/
}

bool Inventory::addItem(Item* item)
{
    if (isInventoryFull())
        return false;
    ActorFactory factory;
    //printf("adding item00\n");
    for (int i=0; i<slotCount; i++)
    {
        if (items[i]->getAnimation() == emptySlot.getAnimation())
        {
            //delete items[i];
            delete items[i];
            //printf("name is = %s\n", item->getName().c_str());
            items[i] = dynamic_cast<Item*>(factory.getActor(item->getName()));
            //items[i] = new Gun();
            //items[i]->setWorld(getWorld());

            //printf("adding item\n");
            items[i] = item;
            //printf("item added\n");
            return true;
        }
        //if (items[i] != emptySlot)
    }
    return false;
}

bool Inventory::isInventoryFull()
{
    for (int i=0; i<slotCount; i++)
    {
        if (items[i]->getAnimation() == emptySlot.getAnimation())
        {
            return false;
        }
    }
    return true;
}

void Inventory::drawInventory()
{
    if (isShown())
    {
        drawImage();
        DrawTextFromRight(get_X() + getWidth()*2/6+10, get_Y() - getHeight()/2+82, 2.5, intToStr(getMoney()) );

        int row = 0;
        int itemNum=0;

            while (slotCount/6 > row)
            {
                for (int col = 0; col<6 ; col++)
                {
                    slot.set_position(get_X() - getWidth()/2+61 + col*100, get_Y() - getHeight()/2+150 + row*100);
                    slot.drawImage();

                    items[itemNum]->set_position(get_X() - getWidth()/2+61 + col*100, get_Y() - getHeight()/2+150 + row*100);
                    items[itemNum]->drawItem();

                    if (slot.isPointInCollision(getWorld()->getCameraX()[0] - getWorld()->maxX/2 + getWorld()->getEvent()->mouseX,
                                                          getWorld()->getCameraY()[0] - getWorld()->maxY/2 + getWorld()->getEvent()->mouseY))
                    {
                        selectedItem.set_position(items[itemNum]->get_X(), items[itemNum]->get_Y());
                        selectedItem.drawImage();
                        currentItem = itemNum;
                        if (getWorld()->getEvent()->isMouseButtonPressedOnce_Left)
                        {
                            if (getCurrentItem()->getAnimation() != emptySlot.getAnimation())
                            {
                                //printf("using item xx\n");
                                //dynamic_cast<Gun*>(getCurrentItem())->use();
                                //printf("item used xx\n");
                                if (dynamic_cast<Equipable*>(getCurrentItem()) != NULL)
                                {
                                    //getCurrentItem()->use();
                                    if (dynamic_cast<Equipable*>(getCurrentItem())->isEquipped())
                                        dynamic_cast<Equipable*>(getCurrentItem())->unequip(owner);
                                    else
                                        dynamic_cast<Equipable*>(getCurrentItem())->equip(owner);

                                }
                                else
                                {
                                    getCurrentItem()->use(owner);
                                    removeCurrentItem();
                                }

                                //dropCurrentItem();
                                //printf("item removed xx\n");
                            }
                        }
                        if (getWorld()->getEvent()->isMouseButtonPressedOnce_Right)
                        {
                            if (getCurrentItem()->getAnimation() != emptySlot.getAnimation())
                            {
                                dropCurrentItem();
                            }
                        }
                        if (getWorld()->getEvent()->isMouseButtonPressedOnce_Middle)
                        {
                            if (getCurrentItem()->getAnimation() != emptySlot.getAnimation())
                            {
                                removeCurrentItem();
                            }
                        }
                    }

                    itemNum++;
                }
                row++;
            }
    }
}

Item* Inventory::getCurrentItem()
{
    return items[currentItem];
}

void Inventory::removeCurrentItem()
{
    if (dynamic_cast<Equipable*>(getCurrentItem()) != NULL)
    {
        if (dynamic_cast<Equipable*>(getCurrentItem())->isEquipped())
            dynamic_cast<Equipable*>(getCurrentItem())->unequip(owner);
    }
    delete items[currentItem];
    items[currentItem] = new EmptySlot();
}

void Inventory::dropCurrentItem()
{
    getCurrentItem()->setOwner(NULL);
    if (dynamic_cast<Equipable*>(getCurrentItem()) != NULL)
    {
        if (dynamic_cast<Equipable*>(getCurrentItem())->isEquipped())
            dynamic_cast<Equipable*>(getCurrentItem())->unequip(owner);
    }
    //set_position(getWorld()->getPlayer()->get_X()+(cos(getWorld()->getPlayer()->getAngle())*1), getWorld()->getPlayer()->get_Y()-(sin(getWorld()->getPlayer()->getAngle())*1));
    getWorld()->addActor(items[currentItem], owner->get_X()+(cos(owner->getAngle())*dropRange),
                          owner->get_Y()-(sin(owner->getAngle())*dropRange));
    //delete items[currentItem];
    items[currentItem] = new EmptySlot();
}

void Inventory::addSlots(int number)
{
    slotCount = slotCount + number;
    if (slotCount>36)
        slotCount = 36;
}

bool Inventory::isShown()
{
    return shown;
}

int Inventory::getMoney()
{
    return currentMoney;
}

bool Inventory::addMoney(int money)
{
    currentMoney = currentMoney + money;
    if (currentMoney > 99999)
    {
        currentMoney = 99999;
        return false;
    }
    return true;
}

bool Inventory::takeMoney(int money)
{
    if (currentMoney - money >=0)
        return true;
    else return false;
}

void Inventory::setMoney(int money)
{
    currentMoney = money;
}

void Inventory::setOwner(Actor *newOwner)
{
    if (dynamic_cast<Player*>(newOwner) != NULL)
    owner = newOwner;
}

Actor* Inventory::getOwner()
{
    return owner;
}
