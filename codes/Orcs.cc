#include "Orcs.h"

Orcs::Orcs(int x_cor, int y_cor, Floor* floor): Enemy{x_cor, y_cor, floor} {
    this->hp = 180;
    this->max_hp = 180;
    this->attack = 30;
    this->defence = 25;
    this->hostile = true;
} 

Orcs::~Orcs() {}