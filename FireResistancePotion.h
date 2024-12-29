#ifndef __FIRERESISTANCEPOTION_H__
#define __FIRERESISTANCEPOTION_H__

#include <iostream>
#include "Potion.h"

class FireResistancePotion : public Potion {
private:
    bool fire_resistance;

public:
    FireResistancePotion();
    void use(Character* character) override;
};

#endif // __FIRERESISTANCEPOTION_H__
