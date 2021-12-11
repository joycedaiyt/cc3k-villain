#include "Item.h"

Item::Item(int x, int y):
    x_cor{x}, y_cor{y}, effect_val{0} {}

Item::~Item() {}

std::string Item::get_effect_type() const {
    return effect_type;
}

void Item::set_effect_val(int val) {
    effect_val = val;
}

int Item::get_effect_val() const {
    return effect_val;
}

bool Item::get_pickup() {
    return true;
}
