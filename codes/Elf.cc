#include "Elf.h"

Elf::Elf(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_max_hp(140);
    set_hp(140);
    set_attack(30);
    set_defense(10);
    set_race("Elf");
    this->hostile = true;
} 

Elf::~Elf() {}

char Elf::get_symbol() {
    return 'E';
}

pair<bool, int> Elf::attack_to(Character& c) {
    if (c.get_race() == "Drow") {
        return c.attacked_by(*this);
    } else {
        auto temp = c.attacked_by(*this);
        return c.attacked_by(*this);
    }
}
