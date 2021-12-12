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

pair<bool, int> Character::attacked_by(Character& c) {
    int attacker_attack = c.get_attack();
    double d = 100 / (100 + (double) get_defense()) * (double) attacker_attack;
    int damage = ceil(d);
    set_hp(get_hp() - damage);
    c.action = c.get_race() + " attacked " + get_race() + " and caused " + to_string(damage) + " damage";
    if (get_hp() <= 0) {
        int drop = this->on_death();
        return make_pair(true, drop);
    } else {
        return make_pair(false, 0);
    }
}

int Character::on_death() {
    return 0;
}

// if return true, attack is successful and the attacked target is dead
pair<bool, int> Character::attack_to(Character& c) {
    return c.attacked_by(*this);;
}
