#include "Item.h"

Item::Item(int x, int y){
	x_cor = x;
	y_cor = y;
	effect_val = 0;
}

const std::string& Item::get_effect_type()const {
	return effect_type;
}

int Item::get_effect_val() const {
	return effect_val;
}
