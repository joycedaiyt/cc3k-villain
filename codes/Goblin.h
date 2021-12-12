#ifndef GOBLIN_H
#define GOBLIN_H
#include "Player.h"

class Goblin: public Player {
    public:
    Goblin(int x_cor, int y_cor, int chamber);
    ~Goblin();
    pair<bool, int> attacked_by(Character& c) override;
};

#endif
