#include "FireResistancePotion.h"

FireResistancePotion::FireResistancePotion() 
    : fire_resistance(true), Potion("Makes Character Resistant to all Fire attacks", "Fire Resistance Potion", 220) {}

void FireResistancePotion::use(Character* character) {
    character->makeFireResistant(); // Apply fire resistance effect to the character
    std::cout << "You are now fire resistant! No fire attacks will damage you." << std::endl;
}
