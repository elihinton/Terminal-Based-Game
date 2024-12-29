#include "Potion.h"

Potion::Potion(const std::string& potionEffect, const std::string& itemName, int itemCost)
    : effect(potionEffect), Item(itemName, "Potion", itemCost) {}

std::string Potion::get_effect() const {
    return effect;
}
