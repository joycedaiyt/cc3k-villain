#include "Character.h"
#include <math.h>

Character::Character(int x_cor, int y_cor) {
    this->x_cor = x_cor;
    this->y_cor = y_cor;
}

Character::~Character() {}

int Character::get_hp() {
    return this->hp;
}

void Character::set_hp(int hp) {
    if (hp >= get_max_hp()) {
        this->hp = get_max_hp();
    } else {
        this->hp = hp;
    }
}
int Character::get_attack() {
    int altered_attack = this->attack;
    for (auto potion: this->temp_potion_effects) {
        if (potion->effect_type == "BA") {
            altered_attack += 5;
        } else if (potion->effect_type == "WA") {
            altered_attack -= 5;
        }
    }
    return altered_attack;
}
void Character::set_attack(int attack) {
    this->attack = attack;
}
int Character::get_defense() {
    int altered_defense = this->defense;
    for (auto potion: this->temp_potion_effects) {
        if (potion->effect_type == "BD") {
            altered_defense += 5;
        } else if (potion->effect_type == "WD") {
            altered_defense -= 5;
        }
    }
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

void Character::attacked_by(Character& c) {
    int attacker_attack = c.get_attack();
    // ceiling((100/(100 + Def(Defender))) ∗ Atk(Attacker))
    int damage = ceil((100/(100 + get_defense())) * attacker_attack);
    set_hp(get_hp() - damage);    
}

void Character::attack_to(Character& c) {
    c.attacked_by(*this);
}

void Character::use_potion(shared_ptr<Potion> potion) {
    if (potion->effect_type == "RH") {
        set_hp(get_hp() + 10);
    } else if (potion->effect_type == "PH") {
        set_hp(get_hp() - 10);
    } else {
        this->temp_potion_effects.push_back(potion);
    }
}
