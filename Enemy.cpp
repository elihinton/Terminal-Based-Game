#include "Enemy.h"

Enemy::Enemy(std::string n, int h, int a_d) 
    : name(n), health(h), attack_damage(a_d) {}

Enemy::Enemy() : Enemy("", 0, 0) {} // Default constructor calls parameterized constructor with default values

std::string Enemy::get_name() const {
    return this->name;
}

void Enemy::set_name(const std::string& new_name) {
    this->name = new_name;
}

int Enemy::get_health() const {
    return this->health;
}

void Enemy::set_health(int new_health) {
    this->health = new_health;
}

int Enemy::get_attack_damage() const {
    return this->attack_damage;
}

void Enemy::set_attack_damage(int new_attack_damage) {
    this->attack_damage = new_attack_damage;
}

Enemy::~Enemy() {} // Virtual destructor; ensure derived class destructors are called
