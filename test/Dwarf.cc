 #include "Dwarf.h"

 Dwarf::Dwarf(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_max_hp(100);
    set_hp(100);
    set_attack(20);
    set_defense(30);
    this->hostile = true;
}

 Dwarf::~Dwarf() {}

char Dwarf::get_symbol() {
    return 'W';
}
