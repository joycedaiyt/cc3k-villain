#include "Gold.h"

Gold::Gold(int x, int y, int value)
    :Item(x, y){
    effect_val = value;
    effect_type = "Gold"; 
    pickup = true;
}

char Gold::get_symbol()
{
    return 'G';
}

void Gold::set_pickup(bool b)
{
    pickup = b;
}

bool Gold::get_pickup()
{
    return pickup;
}
