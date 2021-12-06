#include "Troll.h"

Troll::Troll(int x_cor, int y_cor, Floor* floor, int chamber): Player{x_cor, y_cor, floor, chamber} {
    this->hp = 120;
    this->max_hp = 120;
    this->attack = 25;
    this->defence = 15;
} 

Troll::~Troll() {}