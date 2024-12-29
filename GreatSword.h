#ifndef __GREATSWORD_H__
#define __GREATSWORD_H__

#include "Weapon.h"
#include "Character.h"
#include "Knight.h"
#include <iostream>

class GreatSword : public Weapon, public Knight {
public:
    GreatSword();
    void attack(Character* character, Enemy* opponent);
};

#endif // __GREATSWORD_H__
