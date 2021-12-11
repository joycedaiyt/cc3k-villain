#ifndef GOBLIN_H
#define GOBLIN_H
#include "Player.h"

class Goblin: public Player {
    public:
    Goblin(int x_cor, int y_cor, int chamber);
    ~Goblin();
    void attack_to(Character& c) override;
};

#endif
