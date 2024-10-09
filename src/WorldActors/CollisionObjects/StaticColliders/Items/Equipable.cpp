#include "Equipable.h"
#include "Player.h"

Equipable::Equipable()
{
    equipped = false;
    setBonuses(0,0,0);
    setPercentBonuses(0,0);
    equippedSign.setAnimation("textures/equipped.png",100,100,70,1,1);
    //ctor
}

Equipable::~Equipable()
{
    //dtor
}

void Equipable::equip(Actor *player)
{
    equipPlayer(player);
    use(player);
    printf("equipping\n");
    if (!equipped)
    {
        equipped = true;
        Player* tempPlayer = dynamic_cast<Player*>(player);

        int playerHP           = tempPlayer->getMaxHP();
        int playerStamina      = tempPlayer->getMaxStamina();
        int playerArmor        = tempPlayer->getArmor();
        int playerBonusHP      = tempPlayer->getBonusHP();
        int playerBonusStamina = tempPlayer->getBonusStamina();

        tempPlayer->setMaxHP(playerHP + bonusHP);
        tempPlayer->setMaxStamina(playerStamina + bonusStamina);
        tempPlayer->setArmor(playerArmor + bonusArmor);
        tempPlayer->setBonusHP(playerBonusHP + bonusHP_percent);
        tempPlayer->setBonusStamina(playerBonusStamina + bonusStamina_percent);
    }
}

void Equipable::unequip(Actor *player)
{
    use(player);
    printf("unequipping\n");
    if (equipped)
    {
        equipped = false;
        Player* tempPlayer = dynamic_cast<Player*>(player);

        int playerHP           = tempPlayer->getMaxHP();
        int playerStamina      = tempPlayer->getMaxStamina();
        int playerArmor        = tempPlayer->getArmor();
        int playerBonusHP      = tempPlayer->getBonusHP();
        int playerBonusStamina = tempPlayer->getBonusStamina();

        tempPlayer->setMaxHP(playerHP - bonusHP);
        tempPlayer->setMaxStamina(playerStamina - bonusStamina);
        tempPlayer->setArmor(playerArmor - bonusArmor);
        tempPlayer->setBonusHP(playerBonusHP - bonusHP_percent);
        tempPlayer->setBonusStamina(playerBonusStamina - bonusStamina_percent);
    }
}

void Equipable::setBonuses(int hp, int stamina, int armor)
{
    bonusHP = hp;
    bonusStamina = stamina;
    bonusArmor = armor;
}

void Equipable::setPercentBonuses(int hp, int stamina)
{
    bonusHP_percent = hp;
    bonusStamina_percent = stamina;
}

bool Equipable::isEquipped()
{
    return equipped;
}

void Equipable::drawImage()
{
    Actor::drawImage();
    if (isEquipped())
    {
        equippedSign.set_position(get_X(), get_Y());
        equippedSign.drawImage();
    }
}

void Equipable::equipPlayer(Actor *player)
{

}
