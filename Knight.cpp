#include "Knight.h"

Knight::Knight() 
    : damage(30), max_weapons(2), Character("Knight", 110) {
    weapons = new Weapon*[max_weapons];
    for (int i = 0; i < this->max_weapons; i++) {
        weapons[i] = nullptr; // Initialize weapon slots to nullptr
    }
    equipped_weapon = nullptr; // No weapon equipped initially
}

void Knight::attack(Enemy* target) {
    int newTargetHealth;
    if (this->equipped_weapon != nullptr) {
        newTargetHealth = target->get_health() - equipped_weapon->get_damage();
    } else {
        newTargetHealth = target->get_health() - this->damage;
    }
    target->set_health(newTargetHealth);
}

void Knight::equip_weapon(int position) {
    if (weapons[position] == nullptr) {
        cout << "No weapon in this position" << endl;
        return;
    }
    this->equipped_weapon = this->weapons[position]; // Equip the selected weapon
}

Weapon** Knight::get_weapons() {
    return this->weapons;
}

void Knight::set_damage(int newDamage) {
    this->damage = newDamage;
}

int Knight::get_damage() {
    return this->damage;
}

void Knight::add_weapon(Weapon* weapon) {
    if (weapon->get_type() != "Weapon") {
        return; // Only add items of type "Weapon"
    }
    for (int i = 0; i < this->max_weapons; i++) {
        if (weapons[i] == nullptr) {
            weapons[i] = weapon;
            return;
        }
    }
}

void Knight::print_weapons() {
    cout << "You have ";
    int count = 0;
    for (int i = 0; i < this->max_weapons; i++) {
        if (weapons[i] != nullptr) {
            count++;
        }
    }
    if (count == 0){
        cout << "no weapons \n";
        return;
    } 
    cout << (count == 1 ? "1 weapon:" : to_string(count) + " weapons:") << endl;
    count = 0;
    for (int i = 0; i < this->max_weapons; i++) {
        if (weapons[i] != nullptr) {
            count++;
            cout << "Weapon " << count << ": " << weapons[i]->get_name() 
                 << " -- damage " << weapons[i]->get_damage() << endl;
        }
    }
}

void Knight::increaseStrength(Character* character) {
    if (character->get_name() != "Knight") {
        return; // Only increase strength for Knights
    }
    for (int i = 0; i < this->max_weapons; i++) {
        if (weapons[i] != nullptr) {
            int newDamage = static_cast<int>(weapons[i]->get_damage() * 1.25);
            weapons[i]->set_damage(newDamage); // Increase weapon damage by 25%
        }
    }
    character->set_damage(static_cast<int>(character->get_damage() * 1.25)); // Increase base damage by 25%
    cout << "You have become stronger! You can inflict " << character->get_damage() << " damage" << endl;
    cout << "Your weapons damage has also increased:" << endl;
    character->print_weapons();
}

Weapon* Knight::get_equipped_weapon() {
    return this->equipped_weapon;
}

int Knight::get_max_weapons() const {
    return this->max_weapons;
}

void Knight::restoreMaxMana() {
    cout << "-" << endl;
}

void Knight::print_spells() {
    cout << "-" << endl;
}

int Knight::get_mana() const {
    cout << "-" << endl;
    return 0;
}

Knight::~Knight() {
    for (int i = 0; i < this->max_weapons; i++) {
        delete weapons[i]; // Delete each weapon to free memory
    }
    delete[] weapons; // Delete the weapons array itself
}
