#ifndef TROLL_H
#define TROLL_H
#include "Player.h"

class Troll: public Player {
    public:
    Troll(int x_cor, int y_cor, int chamber);
    ~Troll();
    // Troll gains 5hp after every movement
    void move_effect() override;
};

#endif
