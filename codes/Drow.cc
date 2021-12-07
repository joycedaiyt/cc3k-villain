#include "Drow.h"
#include <cmath>

Drow::Drow(int x_cor, int y_cor, int chamber): Player{x_cor, y_cor, chamber} {
    set_hp(150);
    set_max_hp(150);
    set_attack(25);
    set_defense(15);
} 

Drow::~Drow() {}

void Drow::attacked_by(Enemy& enemy) {
	int damage = ceil((100 / (100 + get_defense())) * enemy.get_attack());
    set_hp(get_hp - damage);
	int newHP = getCurrHP() - damage;
}

void Drow::attack_to(Enemy& enemy) {
	enemy.attacked_by(*this);
}
