#ifndef DROW_H
#define DROW_H
#include "Player.h"

class Drow: public Player {
    public:
    Drow(int x_cor, int y_cor, int chamber);
    ~Drow();
    // Drow has additional potion effect so it need to be overwritten
    //  all potions have their effects maximized by 1.5 times
    int potion_effect(string type, int effect) override;
};

#endif