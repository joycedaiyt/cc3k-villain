#include "Player.h"
#include <math.h>

Player::Player(int x_cor, int y_cor, int chamber):
    Character{x_cor, y_cor}, chamber{ chamber }, gold{0}, prev_loc{'.'} {}

Player::~Player() {}

char Player::get_symbol() {
    return '@';
}

int Player::get_gold() {
    return gold;
}

void Player::attack_by(Enemy& c) {
    int attacker_attack = c.get_attack();
    // ceiling((100/(100 + Def(Defender))) ∗ Atk(Attacker))
    int damage = ceil((100/(100 + get_defense())) * attacker_attack);
    set_hp(get_hp() - damage);    
}

void Player::attack_to(Enemy& c) {
    c.attacked_by(*this);
}

