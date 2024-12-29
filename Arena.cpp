#include "Arena.h"
#include "Witch.h"
#include "Beast.h"
#include "Dragon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Arena::Arena(const std::string& name, const std::string& desc)
    : Location(name, desc) {}

void Arena::enter(Character* player) {
    std::cout << "Welcome to the Arena, " << player->get_name() << "!\n";
    std::cout << "Choose an enemy to fight:\n";
    std::cout << "1. Witch\n";
    std::cout << "2. Beast\n";
    std::cout << "3. Dragon (Vermax)\n";

    int choice;
    while (true) {
        std::cout << "Enter your choice (1-3): ";
        if (std::cin >> choice) {
            if (choice >= 1 && choice <= 3) {
                break; // Valid input
            } else {
                std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
            }
        } else {
            std::cout << "Invalid input. Please enter a valid number.\n";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }
    }
    Enemy* enemy = nullptr;
    switch (choice) {
        case 1:
            enemy = new Witch();
            break;
        case 2:
            enemy = new Beast();
            break;
        case 3:
            std::cout << "Are you sure you would like to challenge Vermax? (y/n): ";
            char confirm;
            std::cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                enemy = new Dragon();
            } else {
                std::cout << "You decided not to fight Vermax.\n";
                return;
            }
            break;
        default:
            std::cout << "Invalid choice. Exiting the Arena.\n";
            return;
    }

    this->battle(player, enemy);

    delete enemy;  // Clean up dynamically allocated enemy
}

void Arena::battle(Character* player, Enemy* enemy) {
    std::cout << "\nBattle Start!\n";

    while (player->get_currentHealth() > 0 && enemy->get_health() > 0) {
        // Display current stats
        std::cout << "\nEnemy Health: " << enemy->get_health() << "\n";
        std::cout << "Your Health: " << player->get_currentHealth() << "/" << player->get_max_health() << "\n";
        if (player->get_mana() >= 0) {
            std::cout << "Your Mana: " << player->get_mana() << "\n";
        }

        // Player's turn
        std::cout << "\nIt's your turn!\n";
        std::cout << "Enter 'a' to attack or 'i' to access inventory: ";
        char choice;
        std::cin >> choice;

        if (choice == 'a' || choice == 'A') {
            player->attack(enemy);
            std::cout << "You attacked the " << enemy->get_name() << "!\n";
        } else if (choice == 'i' || choice == 'I') {
            // Access inventory
            player->printInventory();
            std::cout << "Enter the number of the item to use or 0 to cancel: ";
            int item_choice;
            std::cin >> item_choice;
            if (item_choice > 0 && item_choice <= player->get_inventory_capacity() && player->get_inventory()[item_choice - 1] != nullptr) {
                player->get_inventory()[item_choice - 1]->use(player);
                player->get_inventory()[item_choice - 1] = nullptr; // Remove item from inventory after use
            }
        } else {
            std::cout << "Invalid choice.\n";
        }

        // Check if enemy is defeated
        if (enemy->get_health() <= 0) {
            srand(time(0));
            std::cout << "\nYou defeated the " << enemy->get_name() << "!\n";
            // Award coins based on the type of enemy defeated
            double multiplier = 1 + (rand() / RAND_MAX);
            if (enemy->get_name() == "Witch") {
                int coinsPrize = multiplier * 20;
                player->set_coins(player->get_coins() + coinsPrize);
                std::cout << "You earned" << coinsPrize << "gold!\n";
            } else if (enemy->get_name() == "Beast") {
                int coinsPrize = multiplier * 30;
                player->set_coins(player->get_coins() + coinsPrize);
                std::cout << "You earned" << coinsPrize << "gold!\n";
            } else if (enemy->get_name() == "Vermex") {
                int coinsPrize = multiplier * 1000;
                player->set_coins(player->get_coins() + coinsPrize);
                std::cout << "Congratulations, you defeated the mighty dragon Vermex, the village rejoices!\n";
                std::cout << "You earned" << coinsPrize << "gold!\n";
            }
            break;
        }

        // Enemy's turn
        std::cout << "\nEnemy's turn!\n";
        enemy->perform_attack(player);

        // Check if player is defeated
        if (player->get_currentHealth() <= 0) {
            std::cout << "\nYou have been defeated by the " << enemy->get_name() << ".\n";
            std::exit(0);
            break;
        }
    }
}

Arena::~Arena() {}
