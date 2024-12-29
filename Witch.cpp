#include "Witch.h"
#include "Character.h"
#include <cstdlib>

void Witch::perform_attack(Character* target) {
    srand(time(0));

	double damage = 5 + static_cast<double>(rand() % 15);
    
    target->take_damage(damage);
}