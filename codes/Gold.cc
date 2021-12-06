#include "Gold.h"

Gold::Gold(int x, int y, int type)
    :Item(x, y){
    gold_type = type;
    effect_type = "Gold"; 
    pickup = true;
}

char Gold::get_symbol()
{
    return 'G';
}

int Gold::get_gold_type() {
    return this->gold_type;
}

void Gold::set_pickup(bool b)
{
    pickup = b;
}

bool Gold::get_pickup()
{
    return pickup;
}
