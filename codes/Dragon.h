#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"

class Dragon: public Enemy {
    int gold_x;
    int gold_y;
    public:
    Dragon(int x_cor, int y_cor, int gold_x, int gold_y);
    ~Dragon();
    char get_symbol() override;
    pair<int, int> get_goldcor();
    void attacked_by(Character& c) override;
    void attack_to(Character& c) override;
};

#endif