#ifndef HUMAN_H
#define HUMAN_H
#include "Enemy.h"

class Human: public Enemy {
    public:
    Human(int x_cor, int y_cor);
    ~Human();
    char get_symbol() override;
    void attacked_by(Character& c) override;
    void attack_to(Character& c) override;
};

#endif
