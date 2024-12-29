#ifndef __HEALPOTION_H__
#define __HEALPOTION_H__

#include <iostream>
#include "Character.h"
#include "Potion.h"

class HealPotion : public Potion {
private:
    int healingAmount;

public:
    HealPotion(int h_a);
    HealPotion();
    void use(Character* character) override;
    int getHealingAmount() const;
};

#endif // __HEALPOTION_H__
