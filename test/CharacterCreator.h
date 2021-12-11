#ifndef CHARACTERCREATOR_H
#define CHARACTERCREATOR_H
#include "Character.h"
#include "Enemy.h"
#include "Player.h"
#include "Dragon.h"
#include "Drow.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Goblin.h"
#include "Halfling.h"
#include "Human.h"
#include "Merchant.h"
#include "Orcs.h"
#include "Shade.h"
#include "Troll.h"
#include "Vampire.h"

class CharacterCreator {
    // it is used for creating different character
    // simply enter the name of the character you
    // want to create and it will return a pointer of 
    // that character
    public:
    shared_ptr<Enemy> create_character_by_name(string character_name, int x_cord, int y_cord, int gold_x = 0, int gold_y = 0);
    shared_ptr<Player> create_character_by_name(char race, int x_cord, int y_cord, int chamber_number);
};

#endif
