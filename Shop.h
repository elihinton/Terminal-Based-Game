#ifndef __SHOP_H__
#define __SHOP_H__

#include <iostream>
#include "Item.h"
#include "Character.h"
#include "ManaPotion.h"
#include "StrengthPotion.h"
#include "FireResistancePotion.h"
#include "HealPotion.h"
#include "GreatSword.h"
#include "WarHammer.h"
#include "Location.h"
#include "Weapon.h"

class Shop : Location {
private:
    int manaPotionsCount = 10;
    int strengthPotionsCount = 10;
    int firePotionsCount = 1;
    int healPotionsCount = 10;
    int greatSwordsCount = 10;
    int warHammersCount = 10;
public:
    Shop();
    void buy_item(Character* user, Item* item);
    void buy_weapon(Character* user, Weapon* weapon);
    void enter(Character* user);
};

#endif // __SHOP_H__
