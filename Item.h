#pragma once

#include <string>

class Character;

class Item {
    private:
        std::string name;
        std::string type;
        int coin_cost;

    public:
        Item(std::string n, std::string t, int c);
        virtual void use(Character* character) = 0;
        std::string get_name() const;
        std::string get_type() const;
        void set_name(std::string n_name);
        int get_cost() const;
        void set_cost(int n_cost);
        virtual ~Item();
};