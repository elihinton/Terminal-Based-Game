#ifndef __HELPER_H__
#define __HELPER_H__

#include <iostream>
#include <string>
#include "Character.h"

// unfinished

using namespace std;

class Helper {
    public:
        static void menu(){
            // includes instructions/how to play game and how to quit game
            cout << "\nThe aim of the game is to defeat the dragon Vermax.\n" << endl;
            cout << "There are 4 main locations you should remember:\n\t1. The Village: This is like your homebase where you choose where you would like to travel to next, the guild, the arena or the shop\n\t2. The Arena: This is where you go to battle enemies\n\t3. The Guild: This is where you go to train and improve your health and attack damage\n\t4. The Shop: This is where you can buy weapons (only if you are a knight) or potions to upgrade your character and defeat enemies more easily." << endl;
            cout << endl;
            cout << "Press 'r' then enter at any time to return to the Village." << endl;
            cout << "Press 'm' then enter at any time to view this menu." << endl;
            cout << "Press 'q' then enter to quit the game." << endl;
            cout << "Important Note: You CANNOT return to the Village, view the menu or quit the game during battle.\n" << endl;
            cout << "Now press 'r' to return to the Village or 'q' to quit the game then enter to continue..."<< endl;
            string temp;
            char userInput;
            int count = 0;
            do {
                count++;
                if (count > 1){
                    cout << "Invalid Entry, Please press 'r' or 'q' then enter: ";
                }
                cin >> temp; 
                userInput = temp[0];
            } while ((userInput != 'r' && userInput != 'q') || temp.length() != 1);
            switch(userInput){
                case 'q':
                    quit_game();
                    break;
                default:
                    cout << "village" << endl;
                    // insert village function here
            }
        }
        static void equip_or_use_item(Character* character){
            if (character->get_name() == "Knight"){
                cout << "Would you like to select a weapon (w+enter), use a potion (p+enter), or neither (r+enter) "<< endl;
                string temp;
                char userInput;
                int count = 0;
                do {
                    count++;
                    if (count > 1){
                        cout << "Invalid Entry, Please press 'w' or 'p' then enter: ";
                    }
                    cin >> temp; 
                    userInput = temp[0];
                } while ((userInput != 'w' && userInput != 'p' && userInput != 'q' && userInput != 'r' && userInput != 'm') || temp.length() != 1);
                switch(userInput){
                    case 'q':
                        quit_game();
                        break;
                    case 'w':
                        int num;
                        character->print_weapons();
                        cout << "Which weapon would you like to equip?\n(Enter the weapon number)" << endl;
                        cin >> num;
                        character->equip_weapon(num);
                        break;
                    case 'p':
                        Item** inventory = character->get_inventory();
                        for (int i = 0; i < character->get_inventory_capacity(); i++){
                            if (inventory[i] != nullptr){
                                cout << "Inventory Slot " << i+1 << " - " << inventory[i]->get_name() << endl;
                            }
                        }
                        cout << "Choose which item you would like to use (enter inventory slot number)"<< endl;
                        //use potion logic (get position, get name of item in position, use switch for relevant potion effect, remove from inventory)
                        break;
                    case 'm':
                        Helper::menu();
                        break;
                    default:
                        cout << "village" << endl;
                        // insert village function here
                        
            }
            }
            // wizard potion use (practically same as knight potion use)
        }
        static void quit_game(){
            exit(0);
        }
        static char choose_to_continue_or_otherwise(){
            string temp;
            char userInput;
            int count = 0;
            do {
                count++;
                if (count > 1){
                    cout << "Invalid Entry, Please press 'r', 'q' or 'c' then enter: ";
                }
                cin >> temp; 
                userInput = temp[0];
            } while ((userInput != 'r' && userInput != 'q' && userInput != 'c') || temp.length() != 1);
            return userInput;
        }
};

#endif // __HELPER_H__
