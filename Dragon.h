#ifndef __DRAGON_H__
#define __DRAGON_H__

#include <iostream>
#include <cstdlib>
#include "Enemy.h"

class Dragon : public Enemy {
private:
    int* fire_breath_damage; 
    int strike_count;

public: 
    Dragon();
    void perform_attack(Character* target) override; 
    ~Dragon();
};

#endif // __DRAGON_H__
