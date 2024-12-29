#ifndef __POTION_H__
#define __POTION_H__

#include <iostream>
#include <string>
#include "Item.h"
#include "Character.h"

class Potion : public Item {
private:
    std::string effect;

public:
    Potion(const std::string& potionEffect, const std::string& itemName, int itemCost);
    virtual void use(Character* character) = 0;
    std::string get_effect() const;
};

#endif // __POTION_H__
