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

// we have to find a way to notify other merchant!
pair<bool, int> Merchant::attacked_by(Character& c) {
    this->hostile = 1;
    int attacker_attack = c.get_attack();
    int damage = ceil((100/(100 + get_defense())) * attacker_attack);
    if (get_hp() - damage <= 0) {
        return make_pair(true, 4);
    } else {
        set_hp(get_hp() - damage);
        return make_pair(false, 0);
    }
}

pair<bool, int> Merchant::attack_to(Character& c) {
    if (this->hostile == 1) {
        return c.attacked_by(*this);
    } else {
        return make_pair(false, 0);
    }
}
