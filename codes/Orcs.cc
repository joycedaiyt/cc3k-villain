#include "Orcs.h"

Orcs::Orcs(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_max_hp(180);
    set_hp(180);
    set_attack(30);
    set_defense(25);
    set_race("Orcs");
    this->hostile = true;
} 

Orcs::~Orcs() {}

char Orcs::get_symbol() {
    return 'O';
}
