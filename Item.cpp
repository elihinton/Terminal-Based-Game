#include "Item.h"
#include "Character.h"

Item::Item(std::string n, std::string t, int c) 
    : name(n), type(t), coin_cost(c) {}

std::string Item::get_name() const {
    return name;
}

std::string Item::get_type() const {
    return type;
}

void Item::set_name(std::string n_name) {
    name = n_name;
}

int Item::get_cost() const {
    return coin_cost;
}

void Item::set_cost(int n_cost) {
    coin_cost = n_cost;
}

Item::~Item() {}
