#ifndef EQUIPABLE_H
#define EQUIPABLE_H
#include "Item.h"

class Equipable : public Item
{
    public:
        Equipable();
        virtual ~Equipable();
        virtual void equip(Actor *player);
        virtual void unequip(Actor *player);
        void setBonuses(int hp, int stamina, int armor);
        void setPercentBonuses(int hp, int stamina);
        bool isEquipped();
        void drawImage();
        virtual void equipPlayer(Actor *player);

    protected:

    private:
        Actor equippedSign;
        int bonusHP;
        int bonusArmor;
        int bonusStamina;
        int bonusHP_percent;
        int bonusStamina_percent;
        bool equipped;
};

#endif // EQUIPABLE_H
