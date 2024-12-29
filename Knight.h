#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include <iostream>
#include "Character.h"
#include "Weapon.h"
#include "Enemy.h"

using namespace std;

class Knight : public Character {
private:
    int damage;
    Weapon** weapons;
    int max_weapons;
    Weapon* equipped_weapon;

public:
    Knight();
    void attack(Enemy* target);
    void equip_weapon(int position);
    Weapon** get_weapons();
    void set_damage(int newDamage);
    int get_damage();
    void add_weapon(Weapon* weapon);
    void print_weapons();
    void increaseStrength(Character* character);
    Weapon* get_equipped_weapon();
    int get_max_weapons() const;
    void restoreMaxMana();
    void print_spells();
    int get_mana() const;
    ~Knight();
};

#endif // __KNIGHT_H__
