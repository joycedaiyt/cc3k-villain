#include "Troll.h"

Troll::Troll(int x_cor, int y_cor, int chamber): Player{x_cor, y_cor, chamber} {
    set_max_hp(120);
    set_hp(120);
    set_attack(25);
    set_defense(15);
    set_race("Troll");
} 

Troll::~Troll() {}
