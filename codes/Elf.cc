#include "Elf.h"
#include <math.h>

Elf::Elf(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_hp(140);
    set_max_hp(140);
    set_attack(30);
    set_defense(10);
    this->hostile = true;
} 

Elf::~Elf() {}

char Elf::get_symbol() {
    return 'E';
}

int Elf::attacked_by(Character& c) {
    int attacker_attack = c.get_attack();
    // ceiling((100/(100 + Def(Defender))) ∗ Atk(Attacker))
    int damage = 2 * ceil((100/(100 + get_defense())) * attacker_attack);
    set_hp(get_hp() - damage);
    return damage;
}

int Elf::attacked_by(Drow& c) {
    int attacker_attack = c.get_attack();
    // ceiling((100/(100 + Def(Defender))) ∗ Atk(Attacker))
    int damage = ceil((100/(100 + get_defense())) * attacker_attack);
    set_hp(get_hp() - damage);
    return damage;
}