#include "Orcs.h"

Orcs::Orcs(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_hp(180);
    set_max_hp(180);
    set_attack(30);
    set_defense(25);
    this->hostile = true;
} 

Orcs::~Orcs() {}