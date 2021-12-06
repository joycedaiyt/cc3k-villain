#include "Halfling.h"

Halfling::Halfling(int x_cor, int y_cor, Floor* floor): Enemy{x_cor, y_cor, floor} {
    this->hp = 100;
    this->max_hp = 100;
    this->attack = 15;
    this->defence = 20;
    this->hostile = true;
} 

Halfling::~Halfling() {}