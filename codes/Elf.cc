#include "Elf.h"

Elf::Elf(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_hp(140);
    set_max_hp(140);
    set_attack(30);
    set_defense(10);
    this->hostile = true;
} 

Elf::~Elf() {}