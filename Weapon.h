#pragma once

#include <string>
#include "Item.h"
#include "Enemy.h"

class Weapon : public Item {
private:
    int damage;
    std::string description;

public:
    Weapon(int dmg, const std::string& desc, const std::string& itemName, int itemCost);
    virtual void attack(Character* character, Enemy* opponent) = 0;
    int get_damage() const;
    void set_damage(int dmg);
    std::string get_description() const;
    void use(Character*) override;
};