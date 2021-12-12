#ifndef TROLL_H
#define TROLL_H
#include "Player.h"

class Troll: public Player {
    public:
    Troll(int x_cor, int y_cor, int chamber);
    ~Troll();
    void move_effect() override;
};

#endif
