#include "Character.h"

Character::Character(int x_cor, int y_cor, Floor* floor) {
    this->x_cor = x_cor;
    this->y_cor = y_cor;
    this->floor = floor;
}

Character::~Character() {}

int Character::get_hp() {
    
}