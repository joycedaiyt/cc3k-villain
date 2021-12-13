#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"

class Enemy: public Character {
    public:
    bool hostile;
    int gold_x;
    int gold_y;
    Enemy(int x_cor, int y_cor, int gold_x = 0, int gold_y = 0);
    ~Enemy();
    virtual char get_symbol() = 0;
};

#endif
