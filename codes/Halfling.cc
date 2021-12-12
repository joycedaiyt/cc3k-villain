#include "Halfling.h"

Halfling::Halfling(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_max_hp(100);
    set_hp(100);
    set_attack(15);
    set_defense(20);
    set_race("Halfling");
    this->hostile = true;
} 

Halfling::~Halfling() {}

char Halfling::get_symbol() {
    return 'L';
}

pair<bool, int> Halfling::attacked_by(Character& c) {
    int is_miss = rand() % 1;
    if (is_miss == 0) {
        int attacker_attack = c.get_attack();
        // ceiling((100/(100 + Def(Defender))) ∗ Atk(Attacker))
        int damage = ceil((100/(100 + get_defense())) * attacker_attack);
        if (get_hp() - damage <= 0) {
            int drop = this->on_death();
            return make_pair(true, drop);
        } else {
            set_hp(get_hp() - damage);
        }
    }
    return make_pair(false, 0);
}
