#pragma once
#include "Enemy.h"
#include "Character.h"

class Witch : public Enemy {
    private:
        double damage;
    public:
        Witch() : Enemy("Witch", 50, 12) {};
        void perform_attack(Character*) override;
};