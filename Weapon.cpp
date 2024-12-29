#include "Weapon.h"

Weapon::Weapon(int dmg, const std::string& desc, const std::string& itemName, int itemCost)
    : Item(itemName, "Weapon", itemCost), damage(dmg), description(desc) {}

int Weapon::get_damage() const {
    return damage;
}

void Weapon::set_damage(int dmg) {
    damage = dmg;
}

std::string Weapon::get_description() const {
    return description;
}

void Weapon::use(Character*) {};