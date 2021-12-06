#include "Goblin.h"

Goblin::Goblin(int x_cor, int y_cor, Floor* floor, int chamber): Player{x_cor, y_cor, floor, chamber} {
    this->hp = 110;
    this->max_hp = 110;
    this->attack = 15;
    this->defence = 20;
} 

Goblin::~Goblin() {}