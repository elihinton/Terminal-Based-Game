#ifndef __WIZARD_H__
#define __WIZARD_H__

#include <iostream>
#include <cstdlib>
#include "Character.h"
#include "Enemy.h"

class Wizard : public Character {
private:
    int mana;
    int max_mana;
    std::string* spells;
    int* spells_damage;
    int max_spells;

public:
    Wizard();
    void attack(Enemy* target);
    void increaseStrength(Character* character);
    void print_spells();
    void regenerate_mana(int amount);
    int get_mana() const;
    void reduce_mana(int reduceBy);
    void take_damage(int damage);
    void restoreMaxMana();
    int getMaxSpells() const;
    int* getSpellsDamage() const;
    void set_damage(int newDamage) override;
    int get_damage() override;
    Weapon** get_weapons() override;
    Weapon* get_equipped_weapon() override;
    void print_weapons() override;
    void equip_weapon(int position) override;
    ~Wizard();
};

#endif // __WIZARD_H__
