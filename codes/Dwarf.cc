#include "Dwarf.h"

Dwarf::Dwarf(int x_cor, int y_cor, Floor* floor): Enemy{x_cor, y_cor, floor} {
    this->hp = 100;
    this->max_hp = 100;
    this->attack = 20;
    this->defence = 30;
    this->hostile = true;
} 

Dwarf::~Dwarf() {}
