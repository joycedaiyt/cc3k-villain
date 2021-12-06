#include "Human.h"

Human::Human(int x_cor, int y_cor, Floor* floor): Enemy{x_cor, y_cor, floor} {
    this->hp = 140;
    this->max_hp = 140;
    this->attack = 20;
    this->defence = 20;
    this->hostile = true;
} 

Human::~Human() {}