#include "Potion.h"

Potion::Potion(int x, int y): Item{x, y} {
    effect_type = "Potion";
    effect_val = 0;
}

char Potion::get_symbol() {
    return 'P';
}
