#include <iostream>
#include <string>
#include "Shop.h"
#include "Guild.h"
#include "Knight.h"
#include "Wizard.h"
#include "Arena.h"

using namespace std;

// Display available options in the village
void villagePrintOuts() {
    cout << "Where would you like to go?" << endl;
    cout << "Options are: " << endl;
    cout << "Guild (press g)" << endl;
    cout << "Shop (press s)" << endl;
    cout << "Battle Arena (press b)" << endl;
    cout << "View your Inventory (press i)" << endl;
    cout << "To see your stats (health, inventory, balance), enter 'stats'" << endl;
    cout << "To exit the game, enter 'exit'" << endl;
}

int main() {

    // INTRODUCTION

    // Introduction to the game
    cout << "Welcome to Knights of Valour!" << endl;
    string characterName;

    // Prompt user to select character type
    while (true) {
        cout << "Please Choose Your Character! (knight / wizard): ";
        string input;
        cin >> input;

        // Break loop if valid character is selected
        if (input == "knight" || input == "wizard") {
            characterName = input;
            break;
        }
    }

    // Create character instance based on selection
    Character* character;
    if (characterName == "knight") {
        character = new Knight();
    } else {
        character = new Wizard();
    }

    // Get player's name
    cout << "Greetings " << characterName << "! What is thy name?: ";
    string name;
    cin >> name;
    
    // Introduction to the game story
    cout << "It's a pleasure to meet you " << name << ". Here you will be able to train yourself, buy items and fight enemies in aim of killing the mighty dragon Vermax... Good luck!" << endl;

    // MAIN GAME

    // Initialize game locations: shop, guild, and arena
    Shop shop;
    Guild guild;
    Arena arena("Spell Valley", "A valley of mystical spells and mystical creatures. Who knows what awaits...");

    cout << "Welcome to the village, think of this place as your home, where you can choose to go to the guild, shop, or battle arena." << endl;

    // Main game loop
    while (true) {
        villagePrintOuts(); // Show village options
        string action;
        cin >> action;

        // Handle user's choice
        if (action == "g") {
            guild.enter(character); // Enter guild
        } else if (action == "s") {
            shop.enter(character); // Enter shop
        } else if (action == "b") {
            arena.enter(character); // Enter battle arena
        } else if (action == "exit") {
            exit(0); // Exit the game
        } else if (action == "stats") {
            Knight* knight = dynamic_cast<Knight*>(character);
            Wizard* wizard = dynamic_cast<Wizard*>(character);
            if (knight == nullptr){
                character->printStats(wizard);
            } else {
                character->printStats(knight);
            }
             // Show character stats
        } else if (action == "i") {
            character->printInventory(); // Show character inventory
        } else {
            cout << "Invalid Input!" << endl; // Invalid input handling
        }
    }
}
