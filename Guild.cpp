#include "Guild.h"

Guild::Guild() 
    : Location("Guild", "A place where characters come to train and enhance their abilities.") {}

void Guild::enter(Character* player) {
    if (player->get_coins() < 10) {
        std::cout << "Not enough coins to train! You need 10 coins.\n";
        return;
    }

    // Deduct 10 coins from the player for training
    player->set_coins(player->get_coins() - 10);

    // Increase the player's maximum health by 3%
    int newHealth = static_cast<int>(player->get_max_health() * 1.03);
    player->set_maxHealth(newHealth);
    player->set_currentHealth(newHealth);
   

    // Check if the player is a Wizard using dynamic casting
    Wizard* wizard = dynamic_cast<Wizard*>(player);
    if (wizard) {
        // Get the array of spell damages
        int* spellDamageArray = wizard->getSpellsDamage();
        // Increase each spell's damage by 5%
        for (int i = 0; i < wizard->getMaxSpells(); i++) {
            spellDamageArray[i] = static_cast<int>(spellDamageArray[i] * 1.05);
        }

        std::cout << wizard->get_name() << " has trained. Spell damage increased by 5%, health by 3%.\n"; 
        std::cout << "Spells Damage: ";
        wizard->print_spells();           
    } else {
        // If the player is not a Wizard, check if they are a Knight
        Knight* knight = dynamic_cast<Knight*>(player);
        if (knight) {
            // Increase the Knight's base damage by 5%
            knight->set_damage(static_cast<int>(knight->get_damage() * 1.05));
            std::cout << knight->get_name() << " has trained. Damage increased by 5%, health by 3%.\n";
            std::cout << "Knight Damage: " << knight->get_damage() << std::endl;  

            // Get the Knight's weapons
            Weapon** weapons = knight->get_weapons();
            // Increase the damage of each weapon by 5%
            for (int i = 0; i < knight->get_max_weapons(); i++) {
                if (weapons[i] != nullptr) {
                    // Calculate the new weapon damage
                    int newDamage = static_cast<int>(weapons[i]->get_damage() * 1.05);
                    weapons[i]->set_damage(newDamage);
                }
            }
            knight->print_weapons();
        }         
    }

    // Display training completion message with updated stats
    std::cout << "Training complete. " << player->get_name() << "'s new max health: " 
              << player->get_max_health() << ", coins left: " << player->get_coins() << ".\n";
}
