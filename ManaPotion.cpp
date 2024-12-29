#include "ManaPotion.h"

ManaPotion::ManaPotion(int m_r_a) 
    : mana_restored_amount(m_r_a), Potion("Restore Mana to Maximum", "Mana Potion", 50) {}

ManaPotion::ManaPotion() 
    : ManaPotion(0) {}

void ManaPotion::use(Character* character) {
    if (character->get_name() != "Wizard") {
        std::cout << "Only a Wizard can use the Mana potion." << std::endl;
        return;
    }
    character->restoreMaxMana();
    std::cout << "Your mana has been restored! It is now " << character->get_mana() << std::endl;
}
