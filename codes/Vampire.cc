#include "Vampire.h"

Vampire::Vampire(int x_cor, int y_cor, Floor* floor, int chamber): Player{x_cor, y_cor, floor, chamber} {
    this->hp = 50;
    this->max_hp = 50;
    this->attack = 25;
    this->defence = 25;
} 

Vampire::~Vampire() {}