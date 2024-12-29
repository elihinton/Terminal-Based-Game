#include "Character.h"
#include "Item.h"

#include "Knight.h"
#include "Wizard.h"

#include <iostream>

using namespace std;

Character::Character(std::string n, int h)
    : name(n), currentHealth(h), max_health(h), inventory_capacity(5), coins(100), fire_resistance(false) {
    this->inventory = new Item*[this->inventory_capacity];
    for (int i = 0; i < this->inventory_capacity; i++) {
        inventory[i] = nullptr; // Initialize inventory slots to null pointer
    }
}

void Character::take_damage(int amount) {
    this->currentHealth -= amount;
}

std::string Character::get_name() const {
    return this->name;
}

void Character::add_item(Item* item) {
    if (item->get_type() == "Weapon") {
        std::cout << "Weapons cannot be added to inventory." << std::endl;
        return;
    }
    // Find the first empty slot in the inventory to add the item
    for (int i = 0; i < this->inventory_capacity; i++) {
        if (inventory[i] == nullptr) {
            inventory[i] = item;
            int newBalance = this->get_coins() - item->get_cost();
            this->set_coins(newBalance);
            return;
        }
    }

    cout << "Inventory is full!";
}

int Character::get_coins() const {
    return this->coins;
}

Item** Character::get_inventory() {
    return this->inventory;
}

void Character::set_coins(int coins_now) {
    this->coins = coins_now;
}

int Character::get_currentHealth() const {
    return this->currentHealth;
}

void Character::set_currentHealth(int currentHealth) {
    this->currentHealth = currentHealth;
}

int Character::get_inventory_capacity() const {
    return this->inventory_capacity;
}

void Character::set_fire_resistance(bool fr) {
    this->fire_resistance = fr;
}

bool Character::get_fire_resistance() const {
    return this->fire_resistance;
}

int Character::get_max_health() const {
    return this->max_health;
}

void Character::set_maxHealth(int newMaxHealth) {
    this->max_health = newMaxHealth;
    // Adjust current health if it exceeds the new maximum health
    if (this->currentHealth > newMaxHealth) {
        this->currentHealth = newMaxHealth;
    }
}

void Character::applyHealPotion() {
    this->currentHealth = get_max_health(); // Restore health to maximum
}

void Character::makeFireResistant() {
    if (!get_fire_resistance()) {
        set_fire_resistance(true);
    }
}

void Character::printInventory() {
    int validItems = 0;
    for (int i = 0; i < this->get_inventory_capacity(); i++) {
        if (this->get_inventory()[i] != nullptr) {
            cout << "Inventory slot " << i + 1 << ": " << this->get_inventory()[i]->get_name() << endl;
            validItems++;
        }
    }
    if (validItems == 0){
        cout << "Inventory is empty" << endl;
    }
}

void Character::printStats(Character* character) {
    cout << "Your health is: " << this->get_currentHealth() << endl;
    cout << "Your coin balance is: " << this->get_coins() << endl;
    if (dynamic_cast<Knight*>(character) != nullptr){
        print_weapons(); 
        if (character->get_equipped_weapon() != nullptr){
            cout << "Your equipped weapon is: " << character->get_equipped_weapon()->get_name() << endl; 
        } 
    }
    cout << "Your inventory capacity is: " << this->get_inventory_capacity() << endl;
    cout << "Your damage is: " << this->get_damage() << endl;
    if (dynamic_cast<Wizard*>(character) != nullptr){
        cout << "Your Mana is: " << this->get_mana() << endl; 
    }
}

Character::~Character() {
    // Delete all items in the inventory to prevent memory leaks
    for (int i = 0; i < this->inventory_capacity; i++) {
        delete inventory[i];
    }
    delete[] inventory; // Delete the inventory array itself
}
