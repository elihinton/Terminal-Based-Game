#include "HealPotion.h"

HealPotion::HealPotion(int h_a) 
    : healingAmount(h_a), Potion("Restores character to full health", "Heal Potion", 80) {}

HealPotion::HealPotion() 
    : HealPotion(0) {}

void HealPotion::use(Character* character) {
    character->applyHealPotion(); // Restore character's health to maximum
    std::cout << "You have been healed! Your health is now " << character->get_currentHealth() << std::endl;
}

int HealPotion::getHealingAmount() const {
    return healingAmount;
}
