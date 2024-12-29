#include "Wizard.h"

using namespace std;

// Constructor initializes mana, max_mana, max_spells, and base Character attributes
Wizard::Wizard() : mana(100), max_mana(100), max_spells(5), Character("Wizard", 115) {
    spells = new string[max_spells]{"Fireball", "Ice Shard", "Lightning Bolt", "Arcane Blast", "Meteor Swarm"};
    spells_damage = new int[max_spells]{42, 35, 38, 36, 40};
}

void Wizard::attack(Enemy* target) {
    if (mana < 10) {
        cout << "You don't have enough mana to cast a spell!" << endl;
        return;
    }
    int randomNum = rand() % max_spells; 
    string chosenSpell = spells[randomNum];
    int chosenSpellDamage = spells_damage[randomNum];
    
    reduce_mana(10); // Deduct mana cost for casting a spell

    target->set_health(target->get_health() - chosenSpellDamage);
    cout << "You unleashed a spell: " << chosenSpell << endl;
    cout << target->get_name() << " took " << chosenSpellDamage << " damage.\nThey have " << target->get_health() << endl;
    cout << "Your mana level: " << mana << endl;
}

void Wizard::increaseStrength(Character* character) {
    if (get_name() == "Wizard") {
        for (int i = 0; i < max_spells; i++) {
            spells_damage[i] = static_cast<int>(spells_damage[i] * 1.25); // Increase each spell's damage by 25%
        }
    }
}

void Wizard::print_spells() {
    for (int i = 0; i < max_spells; i++) {
        cout << spells[i] << " -- damage: " << spells_damage[i] << endl;
    }
}

void Wizard::regenerate_mana(int amount) {
    mana += amount;
    cout << "You regenerated " << amount << " mana." << endl;
}

int Wizard::get_mana() const {
    return mana;
}

void Wizard::reduce_mana(int reduceBy) {
    mana -= reduceBy; 
}

void Wizard::take_damage(int damage) {
    cout << "Wizard takes " << damage << " damage!" << endl;
}

void Wizard::restoreMaxMana() {
    if (get_name() == "Wizard") {
        mana = max_mana; // Restore mana to maximum
    }
}

int Wizard::getMaxSpells() const {
    return max_spells;
}

int* Wizard::getSpellsDamage() const {
    return this->spells_damage;
}

void Wizard::set_damage(int newDamage) {
    cout << "Wizards cast spells, so there is no damage to set." << endl;
}

int Wizard::get_damage() {
    // calculates average spell damage and returns
    int* spellsDamage = getSpellsDamage();
    int sum = 0;
    for (int i = 0; i < this->max_spells; i++){
        sum += spellsDamage[i];
    }  
    return sum / this->max_spells;
}

Weapon** Wizard::get_weapons() {
    cout << "Wizards do not have weapons, hence, there are no weapons to get." << endl;
    return nullptr; 
}

Weapon* Wizard::get_equipped_weapon() {
    cout << "Wizards do not have weapons." << endl;
    return nullptr; 
}

void Wizard::print_weapons() {
    cout << "Wizards do not have weapons, hence, there are no weapons to print." << endl;
}

void Wizard::equip_weapon(int position) {
    cout << "Wizards don't have weapons to equip in " << position << endl;
}

Wizard::~Wizard() {
    delete[] spells; // Free dynamically allocated spells array
    delete[] spells_damage; // Free dynamically allocated spells_damage array
}
