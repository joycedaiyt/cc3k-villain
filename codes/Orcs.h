#ifndef ORCS_H
#define ORCS_H
#include "Enemy.h"

class Orcs: public Enemy {
    public:
    Orcs(int x_cor, int y_cor);
    ~Orcs();
    char get_symbol() override;
    // there might be dependency problem
    void attack_to(Goblin& g);
};

#endif
