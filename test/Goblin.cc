#include "Goblin.h"

Goblin::Goblin(int x_cor, int y_cor, int chamber): Player{x_cor, y_cor, chamber} {
    set_max_hp(110);
    set_hp(110);
    set_attack(15);
    set_defense(20);
    set_race("Goblin");
    action += " Goblin's special ability is to steal 5 gold from every slain enemy";
}

Goblin::~Goblin() {}
