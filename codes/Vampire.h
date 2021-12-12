#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "Player.h"

class Vampire: public Player {
    public:
    Vampire(int x_cor, int y_cor, int chamber);
    ~Vampire();
    void set_hp(int hp) override;
    pair<bool, int> attack_to(Character& c) override;
};

#endif
