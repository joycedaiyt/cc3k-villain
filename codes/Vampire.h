#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "Player.h"

class Vampire: public Player {
    public:
    Vampire(int x_cor, int y_cor, int chamber);
    ~Vampire();
    void set_hp(int hp) override;
    void attack_to(Character& c) override;
    void attack_to(Dwarf& c);
};

#endif
