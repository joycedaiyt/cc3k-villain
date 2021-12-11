#include "Drow.h"
#include <cmath>

Drow::Drow(int x_cor, int y_cor, int chamber): Player{x_cor, y_cor, chamber} {
    set_max_hp(150);
    set_hp(150);
    set_attack(25);
    set_defense(15);
    set_race("Drow");
    action += " Drow's special ability is to have all potions have their effect magnified by 1.5";
}

Drow::~Drow() {}

int Drow::use_potion(string type, int effect) {
    int new_effect = effect * 1.5;
    if (type == "RH" || type == "PH") {
        set_hp(get_hp() + new_effect);
    } else if (type == "BA" || type == "WA") {
        temp_atk += new_effect;
    } else {
        temp_def += new_effect;
    }
    return new_effect;
}

void Drow::attacked_by(Enemy& enemy) {
	int damage = ceil((100 / (100 + get_defense())) * enemy.get_attack());
    set_hp(get_hp - damage);
	int newHP = getCurrHP() - damage;
}

void Drow::attack_to(Enemy& enemy) {
	enemy.attacked_by(*this);
}
