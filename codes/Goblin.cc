#include "Goblin.h"

Goblin::Goblin(int x_cor, int y_cor, int chamber): Player{x_cor, y_cor, chamber} {
    set_max_hp(110);
    set_hp(110);
    set_attack(15);
    set_defense(20);
    set_race("Goblin");
    action += " Goblin's special ability is to steal 5 gold from every slain enemy";
} 

Goblin::~Goblin() {}

pair<bool, int> Goblin::attacked_by(Character& c) {
    int attacker_attack = c.get_attack();
    int damage = ceil((100 / (100 + get_defense())) * attacker_attack);
    if (c.get_race() == "Orcs") {
        damage *= 1.5;
    }
    if (get_hp() - damage <= 0) {
        int drop = this->on_death();
        c.action = get_race() + " has been slained and dropped " + to_string(drop) + " gold";
        return make_pair(true, drop);
    } else {
        c.action = c.get_race() + " attacked " + get_race() + " and caused " + to_string(damage) + " damage";
        set_hp(get_hp() - damage);
        return make_pair(false, 0);
    }
}
