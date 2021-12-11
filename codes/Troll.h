#ifndef TROLL_H
#define TROLL_H
#include "Player.h"

class Troll: public Player {
    public:
    Troll(int x_cor, int y_cor, int chamber);
    ~Troll();
    void attacked_by(Character& c) override;
    void attack_to(Character& c) override;
};

#endif
