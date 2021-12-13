#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "Player.h"

class Vampire: public Player {
    public:
    Vampire(int x_cor, int y_cor, int chamber);
    ~Vampire();
    void set_hp(int hp) override;
    // attack_to() needed to be overwritten since vampire attack has special effect to incrase
    // it's hp and it is inverse when attacking dwarf
    pair<bool, int> attack_to(Character& c) override;
};

#endif
