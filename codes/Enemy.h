#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"

class Enemy: public Character {
    public:
    bool hostile;
    int gold_x;
    int gold_y;
    Enemy(int x_cor, int y_cor);
    ~Enemy();
    virtual char get_symbol() = 0;
    // virtual void attacked_by(Character& c);
    // virtual void attack_to(Character& c);
};

#endif
