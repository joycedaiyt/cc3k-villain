#include "Gold.h"

Gold::Gold(int x, int y, int value, bool pickup)
    : Item{x, y} {
    this->pickup = pickup;
    set_effect_val(value);
    effect_type = "Gold"; 
}

char Gold::get_symbol() {
    return 'G';
}
