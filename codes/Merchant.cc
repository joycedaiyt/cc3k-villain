 #include "Merchant.h"

Merchant::Merchant(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_max_hp(100);
    set_hp(100);
    set_attack(20);
    set_defense(30);
    this->hostile = false;
} 

Merchant::~Merchant() {}

char Merchant::get_symbol() {
    return 'M';
}

// we have to find a way to notify other merchant!
int Merchant::attacked_by(Character& c) {
    this->hostile = 1;
    int attacker_attack = c.get_attack();
    // ceiling((100/(100 + Def(Defender))) ∗ Atk(Attacker))
    int damage = ceil((100/(100 + get_defense())) * attacker_attack);
    set_hp(get_hp() - damage);
    return damage;
}

void Merchant::attack_to(Character& c) {
    if (this->hostile == 1) {
        c.attacked_by(*this);
    }
}
