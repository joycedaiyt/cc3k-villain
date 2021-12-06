#include "CharacterCreator.h"
using namespace std;

shared_ptr<Enemy> CharacterCreator::create_character_by_name(string character_name, int x_cord, int y_cord,
    Floor* floor) {
    if (character_name == "human") {
        return make_shared<Human>(x_cord, y_cord, floor);
    } else if (character_name == "dwarf") {
        return make_shared<Dwarf>(x_cord, y_cord, floor);
    } else if (character_name == "elf") {
        return make_shared<Elf>(x_cord, y_cord, floor);
    } else if (character_name == "orcs") {
        return make_shared<Orcs>(x_cord, y_cord, floor);
    } else if (character_name == "merchant") {
        return make_shared<Merchant>(x_cord, y_cord, floor);
    } else if (character_name == "dragon") {
        return make_shared<Dragon>(x_cord, y_cord, floor);
    } else if (character_name == "halfling") {
        return make_shared<Halfling>(x_cord, y_cord, floor);
    }
}

shared_ptr<Player> CharacterCreator::create_character_by_name(string character_name, int x_cord, int y_cord,
    Floor* floor, int chamber_number) {
    if (character_name == "drow") {
        return make_shared<Drow>(x_cord, y_cord, floor, chamber_number);
    } else if (character_name == "shade") {
        return make_shared<Shade>(x_cord, y_cord, floor, chamber_number);
    } else if (character_name == "vampire") {
        return make_shared<Vampire>(x_cord, y_cord, floor, chamber_number);
    } else if (character_name == "goblin") {
        return make_shared<Goblin>(x_cord, y_cord, floor, chamber_number);
    } else if (character_name == "troll") {
        return make_shared<Troll>(x_cord, y_cord, floor, chamber_number);
    }
}