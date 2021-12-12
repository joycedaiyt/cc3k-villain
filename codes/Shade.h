#ifndef SHADE_H
#define SHADE_H
#include "Player.h"

class Shade: public Player {
    public:
    Shade(int x_cor, int y_cor, int chamber);
    ~Shade();
};

#endif
