#include "Human.h"

Human::Human(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_hp(140);
    set_max_hp(140);
    set_attack(20);
    set_defense(20);
    this->hostile = true;
} 

Human::~Human() {}

char Human::get_symbol() {
    return 'H';
}