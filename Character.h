#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Item.h"
#include "Enemy.h"
#include "Weapon.h"

class Item;

class Character {
private:
    std::string name;
    int currentHealth;
    int max_health;
    Item** inventory;
    int inventory_capacity;
    int coins;
    bool fire_resistance;

public:
    Character(std::string n, int h);
    virtual void attack(Enemy* target) = 0;
    void take_damage(int amount);
    std::string get_name() const;
    void add_item(Item* item);
    virtual void increaseStrength(Character* character) = 0;
    int get_coins() const;
    Item** get_inventory();
    void set_coins(int coins_now);
    int get_currentHealth() const;
    void set_currentHealth(int currentHealth);
    int get_inventory_capacity() const;
    void set_fire_resistance(bool fr);
    bool get_fire_resistance() const;
    int get_max_health() const;
    void set_maxHealth(int newMaxHealth);
    void applyHealPotion();
    void makeFireResistant();
    virtual void restoreMaxMana() = 0;
    virtual void set_damage(int newDamage) = 0;
    virtual int get_damage() = 0;
    virtual Weapon** get_weapons() = 0;
    virtual void print_weapons() = 0;
    virtual void print_spells() = 0;
    virtual int get_mana() const = 0;
    virtual Weapon* get_equipped_weapon() = 0;
    virtual void equip_weapon(int position) = 0;
    virtual ~Character();
    void printInventory();
    void printStats(Character* character);
};

#endif // CHARACTER_H
