#include "Dragon.h"

Dragon::Dragon(int x_cor, int y_cor, Floor* floor): Enemy{x_cor, y_cor, floor} {
    this->hp = 150;
    this->max_hp = 150;
    this->attack = 20;
    this->defence = 20;
    this->hostile = true;
} 

Dragon::~Dragon() {}