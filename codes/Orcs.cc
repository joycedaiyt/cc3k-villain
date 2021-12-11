#include "Orcs.h"

Orcs::Orcs(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_max_hp(180);
    set_hp(180);
    set_attack(30);
    set_defense(25);
    this->hostile = true;
} 

Orcs::~Orcs() {}

char Orcs::get_symbol() {
    return 'O';
}

void Orcs::attack_to(Goblin& g) {
    int additional_attack = get_attack() * 0.5;
    set_attack(get_attack() + additional_attack);
    g.attacked_by(*this);
    set_attack(get_attack() - additional_attack);
}
