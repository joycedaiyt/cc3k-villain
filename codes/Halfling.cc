#include "Halfling.h"

Halfling::Halfling(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_hp(100);
    set_max_hp(100);
    set_attack(15);
    set_defense(20);
    this->hostile = true;
} 

Halfling::~Halfling() {}