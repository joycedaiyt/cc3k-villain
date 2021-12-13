#include "Dragon.h"

Dragon::Dragon(int x_cor, int y_cor, int gold_x, int gold_y): 
    Enemy{x_cor, y_cor, gold_x, gold_y} {
    set_max_hp(150);
    set_hp(150);
    set_attack(20);
    set_defense(20);
    set_race("Dragon");
    this->hostile = true;
}

Dragon::~Dragon() {}

char Dragon::get_symbol() {
    return 'D';
}
