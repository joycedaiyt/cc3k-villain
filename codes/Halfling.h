#ifndef HALFLING_H
#define HALFLING_H
#include "Enemy.h"

class Halfling: public Enemy {
    public:
    Halfling(int x_cor, int y_cor);
    ~Halfling();
    char get_symbol() override;
    // Halfling has a 50% chance to make the player miss its attack
    pair<bool, int> attacked_by(Character& c) override;
};

#endif
