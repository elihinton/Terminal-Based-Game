#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <iostream>
#include <string>

class Character;

class Enemy {
    private:
        std::string name;
        int health;
        int attack_damage;

    public:
        Enemy(std::string name, int health, int attackDamage);
        Enemy();
        virtual void perform_attack(Character* target) = 0;
        std::string get_name() const;
        void set_name(const std::string& new_name);
        int get_health() const;
        void set_health(int new_health);
        int get_attack_damage() const;
        void set_attack_damage(int new_attack_damage);
        virtual ~Enemy();
};

#endif // __ENEMY_H__
