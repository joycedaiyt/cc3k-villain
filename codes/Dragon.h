#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"

class Dragon: public Enemy {
    public:
    Dragon(int x_cor, int y_cor, int gold_x, int gold_y);
    ~Dragon();
    char get_symbol() override;
};

#endif
