#include "Merchant.h"

Merchant::Merchant(int x_cor, int y_cor): Enemy{x_cor, y_cor} {
    set_hp(100);
    set_max_hp(100);
    set_attack(20);
    set_defense(30);
    this->hostile = false;
} 

Merchant::~Merchant() {}

char Merchant::get_symbol() {
    return 'M';
}