#include "Merchant.h"

Merchant::Merchant(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_max_hp(100);
    set_hp(100);
    set_attack(20);
    set_defense(30);
    set_race("Merchant");
    this->hostile = false;
} 

Merchant::~Merchant() {}

char Merchant::get_symbol() {
    return 'M';
}

int Merchant::on_death() {
    return 4;
}

pair<bool, int> Merchant::attack_to(Character& c) {
    if (this->hostile == 1) {
        return c.attacked_by(*this);
    } else {
        return make_pair(false, 0);
    }
}
