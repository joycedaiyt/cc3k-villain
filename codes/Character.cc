#include "Character.h"

Character::Character(int x_cor, int y_cor): 
    x_cor{x_cor}, y_cor{y_cor}, temp_atk{0}, temp_def{0} {}

Character::~Character() {}

int Character::get_hp() {
    return this->hp;
}

void Character::set_hp(int hp) {
    int max_hp = this->get_max_hp();
    if (hp >= max_hp) {
        this->hp = max_hp;
    } else {
        this->hp = hp;
    }
}

int Character::get_attack() {
    int altered_attack = this->attack + this->temp_atk;
    return altered_attack;
}

void Character::set_attack(int attack) {
    this->attack = attack;
}

int Character::get_defense() {
    int altered_defense = this->defense + this->temp_def;
    return altered_defense;
}

void Character::set_defense(int defense) {
    this->defense = defense;
}

int Character::get_max_hp() {
    return this->max_hp;
}

void Character::set_max_hp(int max_hp) {
    this->max_hp = max_hp;
}

void Character::set_race(string r) {
    race = r;
}

string Character::get_race() {
    return race;
}

int Character::attacked_by(Character& c) {
    int attacker_attack = c.get_attack();
    // ceiling((100/(100 + Def(Defender))) ∗ Atk(Attacker))
    int damage = ceil((100/(100 + get_defense())) * attacker_attack);
    set_hp(get_hp() - damage);
    return damage;
}

void Character::attack_to(Character& c) {
    int damage = c.attacked_by(*this);
}
