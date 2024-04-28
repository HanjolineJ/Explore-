//#ifndef CHARACTER_H
//#define CHARACTER_H
#include "character.h"
#include <ostream>
#include <iostream>
//#include <string>
//#include <list>


Character::Character(std::string n, int h, int s) : name(n), health(h), strength(s) {}

void Character::display() {
        std::cout << "Name: " << name << ", Health: " << health << ", Strength: " << strength << std::endl;
}

// Add an item to the character's inventory
void Character::addItem(const std::string& item) {
    inventory.push_back(item);
}

// Remove an item from the character's inventory
void Character::removeItem(const std::string& item) {
    inventory.remove(item);
}

// Display the contents of the inventory
void Character::showInventory() const {
    std::cout << "Inventory: ";
    for (const auto& item : inventory) {
        std::cout << item << (item != inventory.back() ? ", " : "");
    }
    std::cout << std::endl;
}
