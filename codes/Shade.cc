#include "Shade.h"

Shade::Shade(int x_cor, int y_cor, int chamber): Player{x_cor, y_cor, chamber} {
    set_hp(125);
    set_max_hp(125);
    set_attack(25);
    set_defense(25);
    set_race("Shade");
} 

Shade::~Shade() {}