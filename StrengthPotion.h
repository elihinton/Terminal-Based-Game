#ifndef __STRENGTHPOTION_H__
#define __STRENGTHPOTION_H__

#include <iostream>
#include "Character.h"
#include "Potion.h"

class StrengthPotion : public Potion {
private:
    int strengthBoost;

public:
    StrengthPotion(int s_boost) : strengthBoost(s_boost), Potion("Increase Character Strength", "Strength Potion", 50) {}
    StrengthPotion() : StrengthPotion(0) {}

    void use(Character* character) override;
};

#endif // __STRENGTHPOTION_H__
