#pragma once

#include <iostream>
#include "WarHammer.h"
#include "HealPotion.h"
#include "Knight.h"
#include "Beast.h" // Include Beast class

class ItemTest {
public:
    void runTests() {
        testWarHammerConstructor();
        testWarHammerGettersSetters();
        testWarHammerUse();
        testHealPotionConstructor();
        testHealPotionUse();
    }

private:
    void testWarHammerConstructor() {
        WarHammer warhammer;
        if (warhammer.get_name() != "War Hammer") {
            std::cout << "WarHammer Constructor Test Failed: Incorrect name" << std::endl;
        }
        if (warhammer.get_type() != "Weapon") {
            std::cout << "WarHammer Constructor Test Failed: Incorrect type" << std::endl;
        }
        if (warhammer.get_cost() != 150) {
            std::cout << "WarHammer Constructor Test Failed: Incorrect cost" << std::endl;
        }
        if (warhammer.get_damage() != 60) {
            std::cout << "WarHammer Constructor Test Failed: Incorrect damage" << std::endl;
        }
        if (warhammer.get_description() != "A heavy war hammer") {
            std::cout << "WarHammer Constructor Test Failed: Incorrect description" << std::endl;
        }
    }

    void testWarHammerGettersSetters() {
        WarHammer warhammer;
        warhammer.set_damage(55);
        warhammer.set_name("Battle Hammer");
        warhammer.set_cost(130);
        if (warhammer.get_damage() != 55) {
            std::cout << "WarHammer SetDamage Test Failed" << std::endl;
        }
        if (warhammer.get_name() != "Battle Hammer") {
            std::cout << "WarHammer SetName Test Failed" << std::endl;
        }
        if (warhammer.get_cost() != 130) {
            std::cout << "WarHammer SetCost Test Failed" << std::endl;
        }
    }

    void testWarHammerUse() {
        WarHammer warhammer;
        Knight knight;
        Beast beast; // Use Beast instead of Enemy

        // Add the weapon to the knight and equip it
        knight.add_weapon(&warhammer);
        knight.equip_weapon(0);

        // Knight attacks the beast
        knight.attack(&beast);
        if (beast.get_health() != 100 - warhammer.get_damage()) {
            std::cout << "WarHammer Use Test Failed: Incorrect enemy health after attack" << std::endl;
        } else {
            std::cout << "Knight attacked Beast, dealing " << warhammer.get_damage() << " damage." << std::endl;
        }

        // Beast performs an attack on the knight
        beast.perform_attack(&knight);
        // You can add assertions to check the knight's health if needed
    }

    void testHealPotionConstructor() {
        HealPotion potion(100);
        if (potion.get_name() != "Heal Potion") {
            std::cout << "HealPotion Constructor Test Failed: Incorrect name" << std::endl;
        }
        if (potion.get_type() != "Potion") {
            std::cout << "HealPotion Constructor Test Failed: Incorrect type" << std::endl;
        }
        if (potion.get_cost() != 80) {
            std::cout << "HealPotion Constructor Test Failed: Incorrect cost" << std::endl;
        }
        if (potion.get_effect() != "Restores character to full health") {
            std::cout << "HealPotion Constructor Test Failed: Incorrect effect" << std::endl;
        }
    }

    void testHealPotionUse() {
        HealPotion potion(100);
        Knight knight;
        knight.set_currentHealth(50);
        potion.use(&knight);
        if (knight.get_currentHealth() != knight.get_max_health()) {
            std::cout << "HealPotion Use Test Failed: Health not restored" << std::endl;
        } else {
            std::cout << "HealPotion used successfully. Knight's health restored to maximum." << std::endl;
        }
    }
};
