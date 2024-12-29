#ifndef __WARHAMMER_H__
#define __WARHAMMER_H__

#include "Weapon.h"
#include "Character.h"
#include "Enemy.h"

class WarHammer : public Weapon {
public:
    WarHammer() : Weapon(80, "A heavy, reliable hammer that deals massive blows", "The War Hammer", 100) {}

    void attack(Character* character, Enemy* opponent);
};

#endif // __WARHAMMER_H__
