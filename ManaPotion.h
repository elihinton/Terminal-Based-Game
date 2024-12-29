#ifndef __MANAPOTION_H__
#define __MANAPOTION_H__

#include <iostream>
#include "Character.h"
#include "Potion.h"

class ManaPotion : public Potion {
private:
    int mana_restored_amount;

public:
    ManaPotion(int m_r_a);
    ManaPotion();
    void use(Character* character) override;
};

#endif // __MANAPOTION_H__
