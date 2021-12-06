#include "Drow.h"

Drow::Drow(int x_cor, int y_cor, Floor* floor, int chamber): Player{x_cor, y_cor, floor, chamber} {
    this->hp = 150;
    this->max_hp = 150;
    this->attack = 25;
    this->defence = 15;
} 

Drow::~Drow() {}