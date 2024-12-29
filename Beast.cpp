#include "Beast.h"

void Beast::perform_attack(Character* target) {
    int targetHealth = target->get_currentHealth();
    int damageInflicted = get_attack_damage();
    int newTargetHealth = targetHealth - damageInflicted;
    target->set_currentHealth(newTargetHealth);

    int num = rand() % 3; // Generate a random number between 0 and 2 to select an attack message

    // Choose an attack description based on the random number
    switch (num) {
        case 0:
            std::cout << "The Beast attacks and deals " << damageInflicted << " damage." << std::endl;
            break;

        case 1:
            std::cout << "The Beast launches onto you, scratching your face and dealing " << damageInflicted << " damage." << std::endl;
            break;

        default:
            std::cout << "The Beast is angry. He beats his chest and pummels you to the ground, dealing " << damageInflicted << " damage." << std::endl;
    }
    std::cout << "You now have " << target->get_currentHealth() << " health." << std::endl;
}
