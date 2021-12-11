#include "Goblin.h"

Goblin::Goblin(int x_cor, int y_cor, int chamber): Player{x_cor, y_cor, chamber} {
    set_hp(110);
    set_max_hp(110);
    set_attack(15);
    set_defense(20);
    set_race("Goblin");
} 

Goblin::~Goblin() {}

void Goblin::attack_to(Character& c) {
    int old_hp = c.get_hp();
    int damage = c.attacked_by(*this);
    if (damage > old_hp) {
        set_gold(get_gold() + 5);
    }
}