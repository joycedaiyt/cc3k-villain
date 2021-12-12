#include "Dragon.h"

Dragon::Dragon(int x_cor, int y_cor, int gold_x, int gold_y): Enemy{x_cor, y_cor} {
    set_max_hp(150);
    set_hp(150);
    set_attack(20);
    set_defense(20);
    set_race("Dragon");
    this->gold_x = gold_x;
    this->gold_y = gold_y;
    this->hostile = true;
}

Dragon::~Dragon() {}

char Dragon::get_symbol() {
    return 'D';
}

pair<int, int> Dragon::get_goldcor() {
    return make_pair(gold_x, gold_y);
}
