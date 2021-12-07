#include "Dragon.h"

Dragon::Dragon(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_max_hp(150);
    set_hp(150);
    set_attack(20);
    set_defense(20);
    this->hostile = true;
} 

Dragon::~Dragon() {}