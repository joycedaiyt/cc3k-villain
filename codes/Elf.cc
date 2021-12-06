#include "Elf.h"

Elf::Elf(int x_cor, int y_cor, Floor* floor): Enemy{x_cor, y_cor, floor} {
    this->hp = 140;
    this->max_hp = 140;
    this->attack = 30;
    this->defence = 10;
    this->hostile = true;
} 

Elf::~Elf() {}