#include "HelmetInstance.h"
#include "Player.h"

HelmetInstance::HelmetInstance()
{
    //ctor
}

HelmetInstance::~HelmetInstance()
{
    //dtor
}

void HelmetInstance::equipPlayer(Actor *player)
{
    Player* tempPlayer = dynamic_cast<Player*>(player);
    if (tempPlayer==NULL)
        return;
    tempPlayer->setHelmet(this);

}

void HelmetInstance::equip(Actor *player)
{
    Player* tempPlayer = dynamic_cast<Player*>(player);
    if (tempPlayer==NULL)
        return;
    if (tempPlayer->getHelmet() !=NULL)
        tempPlayer->getHelmet()->unequip(player);
    Equipable::equip(player);
}
