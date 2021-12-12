#include "Vampire.h"

Vampire::Vampire(int x_cor, int y_cor, int chamber): Player{x_cor, y_cor, chamber} {
    set_max_hp(50);
    set_hp(50);
    set_attack(25);
    set_defense(25);
    set_race("Vampire");
    action += " Vampires's special ability is to gain 5 HP every successful attack and have no maximum HP";
}

Vampire::~Vampire() {}

void Vampire::set_hp(int hp) {
    this->hp = hp;
}

pair<bool, int> Vampire::attack_to(Character& c) {
    string type = c.get_race();
    if (type == "Dwarf") {
        set_hp(get_hp() - 5);
    } else {
        set_hp(get_hp() + 5);
    }
    return c.attacked_by(*this);
}
