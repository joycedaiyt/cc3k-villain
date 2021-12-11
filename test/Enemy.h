#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"

class Enemy: public Character {
    public:
    bool hostile;
    Enemy(int x_cor, int y_cor);
    ~Enemy();
    virtual char get_symbol() = 0;
};

#endif
