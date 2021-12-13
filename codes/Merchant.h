#ifndef MERCHANT_H
#define MERCHANT_H
#include "Enemy.h"

class Merchant: public Enemy {
    public:
    Merchant(int x_cor, int y_cor);
    ~Merchant();
    char get_symbol() override;
    // When a merchant dies it drops a merchant hoard with gold value of 4
    int on_death() override;
    // Merchant only attacks if it is hostile
    pair<bool, int> attack_to(Character& c) override;
};

#endif
