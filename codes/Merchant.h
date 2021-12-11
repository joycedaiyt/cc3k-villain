#ifndef MERCHANT_H
#define MERCHANT_H
#include "Enemy.h"

class Merchant: public Enemy {
    public:
    Merchant(int x_cor, int y_cor);
    ~Merchant();
    char get_symbol() override;
    int attacked_by(Character& c) override;
    void attack_to(Character& c) override;
};

#endif
