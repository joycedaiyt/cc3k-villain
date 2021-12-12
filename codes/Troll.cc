#include "Troll.h"

Troll::Troll(int x_cor, int y_cor, int chamber): Player{x_cor, y_cor, chamber} {
    set_max_hp(120);
    set_hp(120);
    set_attack(25);
    set_defense(15);
    set_race("Troll");
    action += " Troll's special ability is to regain 5 HP every turn";
} 

Troll::~Troll() {}

void Troll::move_effect() {
    set_hp(get_hp() + 5);
    action = "You gained 5 HP";
}
