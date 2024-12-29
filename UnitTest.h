#include <cassert>
#include <iostream>
#include "Knight.h"
#include "ManaPotion.h"
#include "Arena.h"
#include "WarHammer.h"
#include "Beast.h"
#include "HealPotion.h"

class UnitTest {
    public:
        void runTests() {
            Knight* character = new Knight();
            ManaPotion* potion = new ManaPotion();
            Arena* arena = new Arena("test valley", "test_test");
            test_take_damage(character);
            test_add_item(character, potion);
            test_get_coins(character);
            test_set_coins(character);
            test_fire_resistance(character);
            test_inventory_capacity(character);
            test_apply_heal_potion(character);
            test_set_max_health(character);
            test_area_name(arena);
            test_area_description(arena);
            testWarHammerConstructor();
            testWarHammerGettersSetters();
            testWarHammerUse();
            testHealPotionConstructor();
            testHealPotionUse();
            std::cout << "All tests passed!" << std::endl;
        }
    private:
        void test_area_name(Arena* arena) {
            assert(arena->getAreaName() == "test valley");
            std::cout << "test_area_name passed." << std::endl;
        }

        void test_area_description(Arena* arena) {
            assert(arena->getDescription() == "test_test");
            std::cout << "test_area_description passed." << std::endl;
        }

        void test_take_damage(Character* character) {
            character->take_damage(10);
            assert(character->get_currentHealth() == 100);
            std::cout << "test_take_damage passed." << std::endl;
        }

        void test_add_item(Character* character, ManaPotion* potion) {
            character->add_item(potion);
            assert(character->get_inventory()[0] != nullptr);
            std::cout << "test_add_item passed." << std::endl;
        }

        void test_get_coins(Character* character) {
            assert(character->get_coins() == 50);
            std::cout << "test_get_coins passed." << std::endl;
        }

        void test_set_coins(Character* character) {
            character->set_coins(200);
            assert(character->get_coins() == 200);
            std::cout << "test_set_coins passed." << std::endl;
        }

        void test_fire_resistance(Character* character) {
            assert(character->get_fire_resistance() == false); // Initially false

            character->makeFireResistant();
            assert(character->get_fire_resistance() == true); // Should be true after calling makeFireResistant
            std::cout << "test_fire_resistance passed." << std::endl;
        }

        void test_inventory_capacity(Character* character) {
            assert(character->get_inventory_capacity() == 5); // Should be 5 as set in constructor
            std::cout << "test_inventory_capacity passed." << std::endl;
        }
        void test_apply_heal_potion(Character* character) {
            character->take_damage(50);
            assert(character->get_currentHealth() == 50);

            character->applyHealPotion(); // Health should be restored
            assert(character->get_currentHealth() == 110);
            std::cout << "test_apply_heal_potion passed." << std::endl;
        }

        void test_set_max_health(Character* character) {
            character->set_maxHealth(80);  // Lower max health
            assert(character->get_max_health() == 80);
            assert(character->get_currentHealth() == 80);  // Current health should not exceed max health

            character->set_maxHealth(120);  // Increase max health
            assert(character->get_max_health() == 120);
            std::cout << "test_set_max_health passed." << std::endl;
        }

        void testWarHammerConstructor() {
            WarHammer warhammer;
            if (warhammer.get_name() != "The War Hammer") {

                std::cout << warhammer.get_name() << " " << "WarHammer Constructor Test Failed: Incorrect name" << std::endl;
                return;
            }
            if (warhammer.get_type() != "Weapon") {
                std::cout << "WarHammer Constructor Test Failed: Incorrect type" << std::endl;
                return;
            }
            if (warhammer.get_cost() != 100) {
                std::cout << "WarHammer Constructor Test Failed: Incorrect cost" << std::endl;
                return;
            }
            if (warhammer.get_damage() != 80) {
                std::cout << "WarHammer Constructor Test Failed: Incorrect damage" << std::endl;
                return;
            }
            if (warhammer.get_description() != "A heavy, reliable hammer that deals massive blows") {
                std::cout << "WarHammer Constructor Test Failed: Incorrect description" << std::endl;
                return;
            }
            std::cout << "testWarHammerConstructor passed." << std::endl;
        }

    void testWarHammerGettersSetters() {
        WarHammer warhammer;
        warhammer.set_damage(55);
        warhammer.set_name("Battle Hammer");
        warhammer.set_cost(130);
        if (warhammer.get_damage() != 55) {
            std::cout << "WarHammer SetDamage Test Failed" << std::endl;
            return;
        }
        if (warhammer.get_name() != "Battle Hammer") {
            std::cout << "WarHammer SetName Test Failed" << std::endl;
            return;
        }
        if (warhammer.get_cost() != 130) {
            std::cout << "WarHammer SetCost Test Failed" << std::endl;
            return;
        }
        std::cout << "testWarHammerGettersSetters passed." << std::endl;
    }

    void testWarHammerUse() {
        WarHammer* warhammer = new WarHammer();
        Knight knight;
        Beast beast;

        knight.add_weapon(warhammer);
        knight.equip_weapon(0);

        knight.attack(&beast);
        if (beast.get_health() != 100 - warhammer->get_damage()) {
            std::cout << "WarHammer Use Test Failed: Incorrect enemy health after attack" << std::endl;
            return;
        }
        std::cout << "testWarHammerUse passed." << std::endl;
    }

    void testHealPotionConstructor() {
        HealPotion potion(100);
        if (potion.get_name() != "Heal Potion") {
            std::cout << "HealPotion Constructor Test Failed: Incorrect name" << std::endl;
            return;
        }
        if (potion.get_type() != "Potion") {
            std::cout << "HealPotion Constructor Test Failed: Incorrect type" << std::endl;
            return;
        }
        if (potion.get_cost() != 80) {
            std::cout << "HealPotion Constructor Test Failed: Incorrect cost" << std::endl;
            return;
        }
        if (potion.get_effect() != "Restores character to full health") {
            std::cout << "HealPotion Constructor Test Failed: Incorrect effect" << std::endl;
            return;
        }
        std::cout << "testHealPotionConstructor passed." << std::endl;
    }

    void testHealPotionUse() {
        HealPotion potion(100);
        Knight knight;
        knight.set_currentHealth(50);
        potion.use(&knight);
        if (knight.get_currentHealth() != knight.get_max_health()) {
            std::cout << "HealPotion Use Test Failed: Health not restored" << std::endl;
            return;
        }
        std::cout << "testHealPotionUse passed." << std::endl;
    }
};