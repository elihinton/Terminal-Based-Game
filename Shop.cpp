#include "Shop.h"
#include <string>

// Shop constructor initializes with default description
Shop::Shop() : Location("Shop", "A place where characters buy potions and weapons in exchange for coins.") {}

void Shop::buy_item(Character* user, Item* item) {
    // Check if user has enough coins to buy the item
    if (user->get_coins() < item->get_cost()) {
        std::cout << "Insufficient Balance" << std::endl;
        return;
    }

    // Purchase mana potion
    if (dynamic_cast<ManaPotion*>(item)) {
        if (manaPotionsCount > 0) {
            manaPotionsCount--;
            std::cout << "Mana Potion purchased!" << std::endl;
        } else {
            std::cout << "Out of Mana Potions!" << std::endl;
            return;
        }
    // Purchase strength potion
    } else if (dynamic_cast<StrengthPotion*>(item)) {
        if (strengthPotionsCount > 0) {
            strengthPotionsCount--;
            std::cout << "Strength Potion purchased!" << std::endl;
        } else {
            std::cout << "Out of Strength Potions!" << std::endl;
            return;
        }
    // Purchase fire resistance potion
    } else if (dynamic_cast<FireResistancePotion*>(item)) {
        if (firePotionsCount > 0) {
            firePotionsCount--;
            std::cout << "Fire Resistance Potion purchased!" << std::endl;
        } else {
            std::cout << "Out of Fire Resistance Potions!" << std::endl;
            return;
        }
    // Purchase heal potion
    } else if (dynamic_cast<HealPotion*>(item)) {
        if (healPotionsCount > 0) {
            healPotionsCount--;
            std::cout << "Heal Potion purchased!" << std::endl;
        } else {
            std::cout << "Out of Heal Potions!" << std::endl;
            return;
        }
    } else {
        std::cout << "Item not found in shop!" << std::endl;
        return;
    }

    // Deduct the item cost from user's balance and add item to inventory
    int newBalance = user->get_coins() - item->get_cost();
    user->add_item(item);
    std::cout << "Your balance is now: " << user->get_coins() << std::endl;
}

void Shop::buy_weapon(Character* user, Weapon* weapon) {
    // Only knights can buy weapons
    Knight* knightptr = dynamic_cast<Knight*>(user);
    if (knightptr == nullptr) {
        std::cout << "Only knights can buy weapons" << std::endl;
        return;
    }

    // Check if knight has enough coins
    if (knightptr->get_coins() < weapon->get_cost()) {
        std::cout << "Insufficient Balance" << std::endl;
        return;
    }

    // Purchase great sword
    if (dynamic_cast<GreatSword*>(weapon)) {
        if (greatSwordsCount > 0) {
            greatSwordsCount--;
            std::cout << "Great Sword purchased!" << std::endl;
        } else {
            std::cout << "Out of Great Swords!" << std::endl;
            return;
        }
    // Purchase war hammer
    } else if (dynamic_cast<WarHammer*>(weapon)) {
        if (warHammersCount > 0) {
            warHammersCount--;
            std::cout << "War Hammer purchased!" << std::endl;
        } else {
            std::cout << "Out of War Hammers!" << std::endl;
            return;
        }
    }

    // Deduct weapon cost and add it to knight's inventory
    int newBalance = knightptr->get_coins() - weapon->get_cost();
    knightptr->set_coins(newBalance);
    knightptr->add_weapon(weapon);
    std::cout << "Your balance is now: " << knightptr->get_coins() << std::endl;
}

void Shop::enter(Character* user) {
    // Display shop items and costs
    std::cout << "Welcome to the shop! Here is what we have for sale!" << std::endl;
    std::cout << "Your balance is: " << user->get_coins() << std::endl;
    std::cout << "Mana Potions: " << this->manaPotionsCount << " left. Cost 50. Enter 1 to buy." << std::endl;
    std::cout << "Strength Potions: " << this->strengthPotionsCount << " left. Cost 50. Enter 2 to buy." << std::endl;
    std::cout << "Fire Resistance Potions: " << this->firePotionsCount << " left. Cost 220. Enter 3 to buy." << std::endl;
    std::cout << "Healing Potions: " << this->healPotionsCount << " left. Cost 80. Enter 4 to buy." << std::endl;
    std::cout << "Great Swords: " << this->greatSwordsCount << " left. Cost 70. Enter 5 to buy." << std::endl;
    std::cout << "War Hammers: " << this->warHammersCount << " left. Cost 100. Enter 6 to buy." << std::endl;
    std::cout << "Enter 0 to return to the village" << std::endl;

    while (true) {
        std::string input;

        cin >> input;

        if (input == "1") {
            ManaPotion* potion = new ManaPotion(10);
            this->buy_item(user, potion);
        } else if (input == "2") {
            StrengthPotion* potion = new StrengthPotion(10);
            this->buy_item(user, potion);
        } else if (input == "3") {
            FireResistancePotion* potion = new FireResistancePotion();
            this->buy_item(user, potion);
        } else if (input == "4") {
            HealPotion* potion = new HealPotion(50);
            this->buy_item(user, potion);
        } else if (input == "5") {
            GreatSword* weapon = new GreatSword();
            this->buy_weapon(user, weapon);
        } else if (input == "6") {
            WarHammer* weapon = new WarHammer();
            this->buy_weapon(user, weapon);
        } else if (input == "0") {
            return; // Exit shop
        } else {
            std::cout << "Invalid number! Valid numbers: 0-6" << std::endl;
        }
    }

}
