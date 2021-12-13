#ifndef HUMAN_H
#define HUMAN_H
#include "Enemy.h"

class Human: public Enemy {
    public:
    Human(int x_cor, int y_cor);
    ~Human();
    char get_symbol() override;
    // Human drops 2 piles of normal good when it dies
    int on_death() override;
};

#endif
