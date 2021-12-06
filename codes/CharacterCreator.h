#ifndef CharacterCreator_H
#define CharacterCreator_H
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <Enemy.h"
#include "Human.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Orcs.h"
#include "Merchant.h"
#include "Merchant.h"
#include "Dragon.h"
#include "Halfling.h"
#include "Drow.h"
#include "Shade.h"
#include "Vampire.h"
#include "Goblin.h"
#include "Troll.h"

class CharacterCreator {
    // it is used for creating different character
    // simply enter the name of the character you
    // want to create and it will return a pointer of 
    // that character
    public:
    shared_ptr<Player> create_character_by_name(string character_name, 
    int x_cord, int y_cord, Floor* floor, int chamber_number);
    shared_ptr<Enemy> CharacterCreator::create_character_by_name(string character_name, int x_cord, int y_cord,
    Floor* floor);
};

#endif
