#include "Goblin.h"

Goblin::Goblin(int x_cor, int y_cor, int chamber): Player{x_cor, y_cor, chamber} {
    set_hp(110);
    set_max_hp(110);
    set_attack(15);
    set_defense(20);
} 

Goblin::~Goblin() {}
