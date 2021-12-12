#ifndef MERCHANT_H
#define MERCHANT_H
#include "Enemy.h"

class Merchant: public Enemy {
    public:
    Merchant(int x_cor, int y_cor);
    ~Merchant();
    char get_symbol() override;
    pair<bool, int> attacked_by(Character& c) override;
    pair<bool, int> attack_to(Character& c) override;
};

#endif
