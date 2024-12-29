#include "GreatSword.h"

GreatSword::GreatSword() 
    : Weapon(65, "A sleek and powerful blade", "The Great Sword", 70) {}

void GreatSword::attack(Character* character, Enemy* opponent) {
    std::cout << "Great Sword delivers a swift and powerful strike to " << opponent->get_name() << "!" << std::endl;
    
    // Use the Knight's attack method to perform the attack logic
    Knight::attack(opponent);
    
    // Output the damage inflicted
    // Check if the character has a weapon equipped; if not, use the character's base damage
    std::cout << "You have inflicted " << 
        (((character->get_equipped_weapon()) == nullptr) ? 
            (character->get_damage()) : 
            character->get_equipped_weapon()->get_damage()) 
    << " damage" << std::endl; 
    
    std::cout << opponent->get_name() << " now has " << opponent->get_health() << " health" << std::endl;
}
