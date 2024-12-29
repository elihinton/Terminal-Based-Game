#include "WarHammer.h"
#include <iostream>

using namespace std;

void WarHammer::attack(Character* character, Enemy* opponent) {
    cout << "War Hammer attacks " << character->get_name() << " dealing heavy damage!" << endl;
    character->attack(opponent);
    cout << "You have inflicted " << 
    (((character->get_equipped_weapon()) == nullptr) ? 
    (character->get_damage()) : 
    character->get_equipped_weapon()->get_damage()) 
    << " damage" << endl; 
    cout << opponent->get_name() << " now has " << opponent->get_health() << " health" << endl;
}
