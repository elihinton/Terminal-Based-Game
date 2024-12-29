#ifndef __BEAST_H__
#define __BEAST_H__

#include <iostream>
#include <cstdlib>
#include "Enemy.h"
#include "Character.h"  

class Beast : public Enemy {
public:
    Beast() : Enemy("Beast", 100, 25) {}

    void perform_attack(Character* target) override; 
};

#endif // __BEAST_H__
