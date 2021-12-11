#include "Halfling.h"
#include <math.h>

Halfling::Halfling(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_hp(100);
    set_max_hp(100);
    set_attack(15);
    set_defense(20);
    this->hostile = true;
} 

Halfling::~Halfling() {}

char Halfling::get_symbol() {
    return 'L';
}

int Halfling::attacked_by(Character& c) {
    int is_miss = rand() % 1;
    if (is_miss == 0) {
        int attacker_attack = c.get_attack();
        int damage = ceil((100/(100 + get_defense())) * attacker_attack);
        set_hp(get_hp() - damage);
        return damage;
    } else {
        return 0;
    }
}