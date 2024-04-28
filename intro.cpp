#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cctype>
#include <list>

#include "character.h"

int main() {
        std::cout << "Welcome to Explore, a survial based game! " << std::endl;
        // Vector for  characters
        std::vector<Character> characters;

        // Map for setting
        std::map<std::string, std::string> setting;//description
        setting["arena"] = "Forest";//description
        std::map<std::string, std::map<std::string, std::string>> mymap; //map that includes all maps
        mymap["Forest"]["west"]="Field";

        //// Adding characters used chat down
        //characters.push_back(Character("Hero", 100, 75));
        std::string name;
        std::cout << "Enter your character name: ";
        std::cin >> name; //lets player add name
        std::cout << "Here are your stats, ";
        characters.push_back(Character(name, 100, 75));//Display input name
        //characters[0].display();
                                                       //characters.push_back(Character("Bear", 150, 90));//put in later

                                                       // Display characters
        for (auto& character : characters) {
                character.display();
        }

        // Display setting
        std::cout << "You woke up with no memory in the " << setting["arena"] << ". You need to find a way out and survive." << std::endl;

        char direction;
        std::cout << "What direction do you think you should explore? (N/E/S/W): ";
        std::cin >> direction;
        direction = toupper(direction); // convert lowercase to uppercase

        std::map<char, std::string> walk = {
                {'N', "a rusty shovel"},
                {'E', "a tattered Carhartt jacket"},
                {'S', "a beat up first aid kit"},
                {'W', "a bat"}
        };
        auto search = walk.find(direction);
        if (search != walk.end()) {
                std::cout << "As you walk, you discover a " << search->second << std::endl;
                // Ask the player if they want to pick up the item
        char pickup;
        std::cout << "Do you want to pick up the " << search->second << "? (Y/N): ";
        std::cin >> pickup;
        pickup = toupper(pickup);
        if (pickup == 'Y') {
            characters[0].addItem(search->second);
            std::cout << search->second << " added to your inventory." << std::endl;
        } else {
            std::cout << "You decide not to pick up the " << search->second << "." << std::endl;
        }
        } else {
                std::cout << "You have found nothing. Keep walking." << std::endl;
        }

        std::cout << "You hear running from behind you in the opposite direction you went, hurry before the sun sets, what direction do you want to go now? (N/E/S/W): ";
    std::cin >> direction;
    direction = toupper(direction);

    // Encounter bear if going North or East
    if (direction == 'N' || direction == 'E') {
        std::cout << "As you move, you encounter a brown bear!" << std::endl;
        std::cout << "Will you run or fight? (r/f): " << std::endl;
        std::string action;
        std::cin >> action;

        if (action == "f") {
                std::cout << "You are brave and decide to fight! Will you use your it as a weapon?" << std:: endl;
        }else if (action == "r") {
                std::cout << "Your are smart and run fast towards the sound of the water! " << std::endl;
        } else {
                std::cout << "You have to pick (r or f) hurry the bear is coming closer!" << std::endl;
        }
    } else {
        std::cout << "You continue moving, you here the water more, sounds like a creek." << std::endl;
    }


        std::cout << "Your inventory: " << std::endl;
        characters[0].showInventory();

        return 0;
}
