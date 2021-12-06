#include "Shade.h"

Shade::Shade(int x_cor, int y_cor, Floor* floor, int chamber): Player{x_cor, y_cor, floor, chamber} {
    this->hp = 125;
    this->max_hp = 125;
    this->attack = 25;
    this->defence = 25;
} 

Shade::~Shade() {}