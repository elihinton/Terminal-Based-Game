#include "StrengthPotion.h"

void StrengthPotion::use(Character* character) {
    if (character->get_name() == "Knight") {
        character->increaseStrength(character);
        std::cout << "Your damage is now " << character->get_damage() << std::endl;
        if (character->get_weapons()) {
            std::cout << "Your weapons also now do more damage: " << std::endl;
            character->print_weapons();
        }
    } else {
        character->increaseStrength(character);
        std::cout << "Your spells damage has been upgraded: " << std::endl;
        character->print_spells();
    }
}
