#include "CharacterCreator.h"
using namespace std;

shared_ptr<Enemy> CharacterCreator::create_character_by_name(string character_name, int x_cord, int y_cord, int gold_x, int gold_y) {
    if (character_name == "human") {
        return make_shared<Human>(x_cord, y_cord);
    } else if (character_name == "dwarf") {
        return make_shared<Dwarf>(x_cord, y_cord);
    } else if (character_name == "elf") {
        return make_shared<Elf>(x_cord, y_cord);
    } else if (character_name == "orcs") {
        return make_shared<Orcs>(x_cord, y_cord);
    } else if (character_name == "merchant") {
        return make_shared<Merchant>(x_cord, y_cord);
    } else if (character_name == "dragon") {
        return make_shared<Dragon>(x_cord, y_cord, gold_x, gold_y);
    } else if (character_name == "halfling") {
        return make_shared<Halfling>(x_cord, y_cord);
    }
    return 0;
}

shared_ptr<Player> CharacterCreator::create_character_by_name(char race, int x_cord, int y_cord, int chamber_number) {
    if (race == 'd') {
        return make_shared<Drow>(x_cord, y_cord, chamber_number);
    } else if (race == 's') {
        return make_shared<Shade>(x_cord, y_cord, chamber_number);
    } else if (race == 'v') {
        return make_shared<Vampire>(x_cord, y_cord, chamber_number);
    } else if (race == 'g') {
        return make_shared<Goblin>(x_cord, y_cord, chamber_number);
    } else if (race == 't') {
        return make_shared<Troll>(x_cord, y_cord, chamber_number);
    }
    return 0;
}