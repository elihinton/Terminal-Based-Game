#include "Dragon.h"
#include "Character.h"

Dragon::Dragon() : Enemy("Dragon", 300, 45), strike_count(0) {
    // Initialize fire breath damage array with predefined damage values
    fire_breath_damage = new int[4]{112, 99, 105, 95}; 
}

void Dragon::perform_attack(Character* target) {
    if (target->get_fire_resistance()) {
        // Special attack sequence when the character has fire resistance
        if (strike_count == 0) {
            std::cout << "The mighty Dragon VERMAX can smell your potion. Your sorcery angers him!" << std::endl;
            std::cout << "He pins you to ground, breathing fire into you." << std::endl;
            std::cout << "It does not work! Good for you ... " << std::endl;
            std::cout << "He swipes his mighty claw, striking you hard and deals " << get_attack_damage() << " damage " << std::endl;
            std::cout << "You now have " << target->get_currentHealth() << " health." << std::endl;
            strike_count++; // Increment strike count after first special attack
        } else {
            std::cout << "He swipes his mighty claw, striking you hard and deals " << get_attack_damage() << " damage " << std::endl;
            std::cout << "You now have " << target->get_currentHealth() << " health." << std::endl;
        }
    } else { // When character has no fire resistance
        int num = rand() % 4; // Randomize the attack by selecting an index between 0 and 3
        int currentHealth = target->get_currentHealth();
        
        // Use the selected fire breath damage value based on the random number
        switch (num) {
            case 0:
                target->set_currentHealth(currentHealth - fire_breath_damage[0]);
                std::cout << "Vermax attacks and deals " << fire_breath_damage[0] << " damage " << std::endl;
                break;

            case 1:
                target->set_currentHealth(currentHealth - fire_breath_damage[1]);
                std::cout << "Vermax is furious today! He smacks you to the floor dealing " << fire_breath_damage[1] << " damage " << std::endl;
                break;

            case 2:
                target->set_currentHealth(currentHealth - fire_breath_damage[2]);
                std::cout << "Vermax is furious today! He smacks you to the floor dealing " << fire_breath_damage[2] << " damage " << std::endl;
                break;

            default:
                target->set_currentHealth(currentHealth - fire_breath_damage[3]);
                std::cout << "Vermax swipes his claw dealing " << fire_breath_damage[3] << " damage " << std::endl;
        }
        std::cout << "You now have " << target->get_currentHealth() << " health." << std::endl;
    }
}

Dragon::~Dragon() {
    delete[] fire_breath_damage; // Free the dynamically allocated damage array
}
